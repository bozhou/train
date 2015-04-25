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
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

int a[666];

int main()
{

	int n, k;
	while (cin >> n >> k)
	{
		n++;
		int s=0,l=0,r;
		REP(i, 0, n){
			scanf("%d", a + i);
			s += a[i];
			l = max(l, a[i]);
		}

		r = s;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			int d = 1;
			int c = 0;
			REP(i, 0, n)
			{
				if (c + a[i] > m) {
					d++; c = a[i];
				}
				else c += a[i];
			}
			if (d <= k + 1) r = m - 1;
			else l = m + 1;
		}
		cout << l<<endl;

	}

	return 0;
}