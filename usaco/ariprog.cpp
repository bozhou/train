/*
ID: zapray.1
PROG: ariprog
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


bool t[125005];

//#define LOCAL
int main() {
	#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#else
	freopen("ariprog.out", "w", stdout);
	freopen("ariprog.in", "r", stdin);
	#endif // LOCAL	

	int n,m;
	cin >> n>>m;
	for (int p = 0; p <= m; p++)
		for (int q = 0; q <= m; q++)
			t[p*p + q*q] = 1;
	int M = m*m *2;

	bool gotone = 0;
	for (int b = 1; b <= M / (n-1); b++)
		for (int a = 0; a + b*(n-1) <= M; a++)
		{
			bool ok=1;
			for (int k = 0; ok&& k < n; k++) ok &= t[a + k*b];
			if (ok)
			{
				gotone = 1;
				printf("%d %d\n", a, b);
			}
		}
	if (!gotone) puts("NONE");

	//cout << ans<<endl;

	return 0;
}