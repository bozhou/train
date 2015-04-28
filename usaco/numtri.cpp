/*
ID: zapray.1
PROG: numtri
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
#define REP(i,s,t) for(int i=(s); i<(t); i++)
#define FILL(x,v) memset(x,v, sizeof(x))

int a[1005][1005];
int dp[1005][1005];

//#define LOCAL
int main() {
	#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#else
	freopen("numtri.out", "w", stdout);
	freopen("numtri.in", "r", stdin);
	#endif // LOCAL	
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			scanf("%d", &(a[i][j]));
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
	cout << dp[0][0] << endl;

	return 0;
}