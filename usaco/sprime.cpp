/*
ID: zapray.1
PROG: sprime
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


int n;
bool isprime(int x)
{
	if (x == 1) return 0;
	if (x == 2) return 1;
	for (int i = 2; i*i <= x; i++)
		if (x%i == 0) return 0;
	return 1;
}

void dfs(int d, int x)
{
	if (d == n)
		cout << x << endl;
	else
	{
		int nd;
		if (d == 0)
		{
			nd = 2;
			int nx = x * 10 + nd;
			if (isprime(nx))
				dfs(d + 1, nx);
		}
		for (nd = 1; nd < 10; nd += 2)
		{
			int nx = x * 10 + nd;
			if (isprime(nx))
				dfs(d + 1, nx);
		}
	}
}



//#define LOCAL
int main() {
	#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#else
	freopen("sprime.out", "w", stdout);
	freopen("sprime.in", "r", stdin);
	#endif // LOCAL	
	
	cin >> n;
	
	dfs(0,0);

	return 0;
}