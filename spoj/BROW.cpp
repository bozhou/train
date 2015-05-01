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

int d[30005];
int b[30005];

int ds[30005];
int bs[30005];


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d", b + i, d + i);
		}

		for (int i = 1; i <= n; i++)
		{
			b[i + 2 * n] = b[i + n] = b[i];
			d[i + 2 * n] = d[i + n] = d[i];
		}
		b[0] = d[0] = bs[0] = ds[0] = 0;
		for (int i = 1; i <= 3 * n; i++)
		{
			bs[i] = b[i] + bs[i - 1];
			ds[i] = d[i - 1] + ds[i - 1];
		}

		ll cost = 0;
		int l, r, m = n+1;
		for (l = m; ds[m] - ds[l] <= ds[l+n] - ds[m]; l--);
		l++;
		r = l + n - 1;
		for (int i = l; i <= r; i++)
			cost += (ll)b[i] * abs(ds[m]-ds[i]);

		ll ans = cost;
		for (m = n+2; m <= 2*n; m++)
		{
			cost += (ll)d[m - 1] * ((bs[m - 1] - bs[l-1]) - (bs[r] - bs[m - 1]));
			
			while (ds[m] - ds[l] > ds[l + n] - ds[m])
			{
				l++; r++;
				cost += (ll)b[r] * ((ds[r] - ds[m]) - (ds[m] - ds[l - 1]));
			}
			ans = min(ans, cost);
		}
		cout << ans << endl;
	}


	return 0;
}