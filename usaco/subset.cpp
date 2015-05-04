/*
ID: zapray.1
PROG: subset
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


//#define LOCAL
int main() {
#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("subset.out", "w", stdout);
	freopen("subset.in", "r", stdin);
#endif // LOCAL	

	int n;
	cin >> n;
	ll dp[2][10000] = { 0 };
	dp[0][0] = 1;
	int maxs = (1 + n)*n / 2;
	

	if (maxs & 1)
	{
		cout << 0 << endl;
		return 0;
	}
	else maxs /= 2;

	int c = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= maxs; j++)
			dp[c][j] = dp[c ^ 1][j];
		for (int j = 0; j <= maxs-i; j++)
			if (dp[c ^ 1][j])
				dp[c][j + i] += dp[c ^ 1][j];
		c ^= 1;
	}
	cout << dp[c ^ 1][maxs]/2 << endl;


	return 0;
}