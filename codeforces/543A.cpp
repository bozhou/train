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

ll dp[2][1005][505];
int n, m, b, MOD;

int main()
{
	cin >> n >> m >> b >> MOD;

	int a[505];
	for (int i = 1; i <= n; i++) scanf("%d", a + i);

	dp[0][0][0] = 1;

	int pre, cur;
	for (int i = 1; i <= n; i++)
	{
		cur = i % 2;
		pre = 1 - cur;
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= b; k++)
					dp[cur][j][k] = dp[pre][j][k];
		for (int j = 0; j < m; j++)
			for (int k = 0; k + a[i] <= b; k++)
				if (dp[cur][j][k])
				{
					dp[cur][j + 1][k + a[i]] += dp[cur][j][k];
					dp[cur][j + 1][k + a[i]] %= MOD;
				}

	}
	ll ans = 0;
	for (int i = 0; i <= b; i++)
	{
		ans += dp[cur][m][i];
		ans %= MOD;
	}
	cout << ans << endl;

	return 0;
}