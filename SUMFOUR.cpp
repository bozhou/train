#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cassert>
#include <unordered_map>


using namespace std;
typedef long long ll;
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define EPS 1E-9

int a[4][4005];

#define hf1(x) ((unsigned)2654435761*(x))
#define H_BITS 26 // Hashtable size
#define H_SHIFT (32-H_BITS)
int h1[1 << H_BITS][2] = { 0 };

int main()
{
	int n;
	scanf("%d", &n);
	//clock_t start = clock();

	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", a[0] + i, a[1] + i, a[2] + i, a[3] + i);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int key = a[0][i] + a[1][j];
			unsigned s1 = hf1(key) >>  H_SHIFT;
			while (h1[s1][1] > 0 && h1[s1][0] != key)
			{
				s1++;
				if (s1 == (1 << H_BITS)) s1 = 0;
			}
			h1[s1][0] = key;
			h1[s1][1]++;
		}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int key = -a[2][i] - a[3][j];
			unsigned s1 = hf1(key) >> H_SHIFT;
			while (h1[s1][1] > 0 && h1[s1][0] != key)
			{
				s1++;
				if (s1 == (1 << H_BITS)) s1 = 0;
			}
			ans += h1[s1][1];
		}


	printf("%lld\n", ans);
	return 0;
}