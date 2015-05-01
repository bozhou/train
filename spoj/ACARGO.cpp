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

typedef pair<int, int> PII;

ll p[200005];

int main()
{
	int n, l;
	while (cin >> n >> l, (n && l))
	{
		ll t;
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &t);
			p[i] = t;
			p[i + n] = t+l;
		}
		sort(p, p + 2 * n);
		for (int i = 1; i < 2 * n; i++)
			p[i] += p[i - 1];

		ll ans = LLONG_MAX;
		for (int i = 0; i < n; i++)
		{
			int j = i + n - 1;
			ll tmp;
			if (n % 2)
			{
				int m = (i + j) / 2;
				tmp = p[j] - p[m - 1] - (p[m] - p[i - 1]);
				tmp -= (ll)(n - 1 + 2)*((n - 1 - 2) / 2 + 1) / 2;
			}
			else
			{
				int m1 = (i + j) / 2;
				int m2 = (i + j + 1) / 2;
				tmp = p[j] - p[m2 - 1] - (p[m1] - p[i - 1]);
				tmp -= (ll)(n - 1 + 1)*((n - 1 - 1) / 2 + 1) / 2;
			}
			ans = min(ans, tmp);
		}

		cout << ans << endl;

	
	}
	

	return 0;
}