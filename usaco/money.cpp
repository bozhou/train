/*
ID: zapray.1
PROG: money
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
#include <unordered_set>

using namespace std;
typedef long long ll;
#define REP(i,s,t) for(int i=(s); i<(t); i++)
#define FILL(x,v) memset(x,v, sizeof(x))


ll dp[26][10005];

//#define LOCAL
int main() {
#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("money.out", "w", stdout);
	freopen("money.in", "r", stdin);
#endif // LOCAL	

	int c[26];
	dp[0][0] = 1;
	int v, n;
	cin >> v >> n;
	for (int i = 0; i < v; i++) cin >> c[i];
	for (int i = 0; i < v; i++)
		for (int j = 0; j <= n; j++)
		{
			if (dp[i][j])
				for (int k = 0; j + k*c[i] <= n; k++)
					dp[i+1][j + k*c[i]] += dp[i][j];
		}
	cout << dp[v][n] << endl;
}