/*
ID: zapray.1
PROG: combo
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


int dist(int x, int y, int n)
{
	return min(min(abs(x - y), abs(x + n - y)), abs(y + n -x ));
}

int main() {
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);


	int n;
	cin >> n;
	int v[3],u[3];
	cin >> v[0] >> v[1] >> v[2];
	cin >> u[0] >> u[1] >> u[2];


	int ans = 1;
	REP(i, 0, 3)
	{ 
		int p = 0;
		REP(k, 1, n + 1)
			p += (dist(k, v[i],n) <= 2 && dist(k, u[i],n) <= 2);
		ans *= p;
	}

	int s = min(5, n) * min(5, n) *min(5, n);
	ans = 2 * s - ans;

	cout << ans << endl;
	
	return 0;
}