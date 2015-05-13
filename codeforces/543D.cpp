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


using namespace std;
typedef long long ll;
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define EPS 1E-9
#define INF 1E12
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

typedef pair<int, int> PII;


#define MOD 1000000007

ll pw(ll x, ll y, ll m = LLONG_MAX)
{
	ll ans = 1;
	while (y)
	{
		if (y&(1ll)) { ans *= x; ans %= m; }
		x *= x; x %= m;
		y >>= 1;
	}
	return ans;
}

ll inv(ll x, ll m = LLONG_MAX)
{
	return pw(x, m - 2, m);
}


vector<ll> dp[200005];
vector<int> e[200005];
ll ans[200005];
vector<ll> leftmul[200005];
vector<ll> rightmul[200005];


ll solve(int x, int ne)
{
	if (dp[x][ne] < 0)
	{
		dp[x][ne] = 1;
		if (ans[x] >= 0)
		{
			int i = ne;
			int y = e[x][i];
			int nne = lower_bound(e[y].begin(), e[y].end(), x) - e[y].begin();

			if (e[x].size() == 1) dp[x][ne] = 1;
			else if (i - 1 < 0)
				dp[x][ne] = rightmul[x][i+1];
			else if (i == e[x].size()-1)
				dp[x][ne] = leftmul[x][i-1];
			else dp[x][ne] = leftmul[x][i - 1] * rightmul[x][i + 1];
			dp[x][ne] %= MOD;
		}
		else
			for (int i = 0; i < e[x].size(); i++)
			{
				if (i == ne) continue;
				int y = e[x][i];
				int nne = lower_bound(e[y].begin(), e[y].end(), x) - e[y].begin();
				dp[x][ne] *= solve(y, nne) + 1;
				dp[x][ne] %= MOD;
			}
	}
	dp[x][ne] %= MOD;
	return dp[x][ne];
}

ll solve(int x)
{
	if (ans[x] < 0)
	{
		ans[x] = 1;
		for (int i = 0; i < e[x].size(); i++)
		{
			int y = e[x][i];
			int nne = lower_bound(e[y].begin(), e[y].end(), x) - e[y].begin();
			ans[x] *= solve(y, nne) + 1;
			ans[x] %= MOD;
			leftmul[x].push_back(solve(y, nne) + 1);
		}
		rightmul[x] = leftmul[x];
		for (int i = 1; i < e[x].size(); i++)
		{
			leftmul[x][i] *= leftmul[x][i -1];
			leftmul[x][i] %= MOD;
		}
		for (int i = e[x].size() - 2; i >= 0; i--)
		{
			rightmul[x][i] *= rightmul[x][i + 1];
			rightmul[x][i] %= MOD;
		}
	}
	return ans[x];
}



int main()
{
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int p;
		scanf("%d", &p);
		e[i].push_back(p);
		e[p].push_back(i);
	}
	FILL(ans, -1);
	for (int i = 1; i <= n; i++)
	{
		dp[i] = vector<ll>(e[i].size() + 1, -1);
	}
	for (int i = 1; i <= n; i++)
		sort(e[i].begin(), e[i].end());

	for (int i = 1; i <= n; i++)
		cout << solve(i) << " ";

	cout << endl;

	return 0;
}