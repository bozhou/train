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
#define INF 1E12
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

#define MAXN 200005

int a[MAXN];
int d[MAXN];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	FILL(d, 0);
	for (int i = 2; i <= n; i++)
	{
		int j = i - 1;
		int kl, kh=0;
		while (kh < n-1)
		{
			kl = (i - 1 +j -1) / j;
			if (j>1) kh = (i - 2) / (j - 1);
			else kh = n-1;

			if (a[i] < a[j])
			{
				d[kl]++;
				d[kh + 1]--;
			}
			j = (i - 1  + kh ) / (kh + 1);
		}
	}
	int s = 0;
	for (int i = 1; i < n; i++)
	{
		s += d[i];
		printf("%d ", s);
	}


	return 0;
}