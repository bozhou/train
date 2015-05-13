/*
ID: zapray.1
PROG: nocows
LANG: C++11              
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <climits>
#include <cassert>

using namespace std;
typedef long long ll;
#define REP(i,s,t) for(int i=(s); i<(t); i++)
#define FILL(x,v) memset(x,v, sizeof(x))

#define MOD 9901

int dp[205][105];


//#define LOCAL
int main() {
#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("nocows.out", "w", stdout);
	freopen("nocows.in", "r", stdin);
#endif // LOCAL	

	int n, k;
	cin >> n >> k;

	dp[1][1] = 1;

	for (int i = 3; i <= n; i+=2)
		for (int j = 1; j <= k; j++)
		{
			for (int l = 1; l <= i - 2; l+=2)
			{
				int r = i - 1 - l;
				for (int oj = 1; oj < j - 1; oj++)
				{
					dp[i][j] += (dp[l][j - 1] * dp[r][oj]) % MOD;
					dp[i][j] += (dp[l][oj] * dp[r][j - 1]) % MOD;
					dp[i][j] %= MOD;
				}
				dp[i][j] += (dp[l][j-1] * dp[r][j - 1]) % MOD;
				dp[i][j] %= MOD;
			}
		}

	cout << dp[n][k]<<endl;

	return 0;
}