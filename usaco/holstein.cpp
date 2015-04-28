/*
ID: zapray.1
PROG: holstein
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
int cnt[4];
char a[1005];

int countbits(int x)
{
	int ans = 0;
	while (x&(-x))
	{
		ans++; x &= (x - 1);
	}
	return ans;
}

bool small(int x, int y)
{
	if (countbits(x) == countbits(y))
		return (x < y);
	else return (countbits(x) < countbits(y));
}


//#define LOCAL
int main() {
#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("holstein.out", "w", stdout);
	freopen("holstein.in", "r", stdin);
#endif // LOCAL	


	int v;
	cin >> v;
	int vs[30];
	for (int i = 0; i < v; i++) cin >> vs[i];
	
	int g;
	cin >> g;
	int a[18][28];

	for (int i = 0; i < g; i++)
		for (int j = 0; j < v; j++)
			cin >> a[i][j];
	
	int Mk=(1<<g)-1;
	for (int k = 0; k < (1 << g); k++)
	{
		int got[30];
		FILL(got, 0);
		for (int i = 0; i < g; i++)
			if (k&(1 << i))
				for (int j = 0; j < v; j++)
				{
					got[j] += a[i][j];
				}
		bool ok=1;
		for (int i = 0; i < v; i++) ok &= (got[i]>=vs[i]);
		if (ok && small(k, Mk)) { Mk = k; }
	}

	cout << countbits(Mk) << " ";
	for (int i = 0; i < g; i++)
		if (Mk&(1 << i))
		{
			Mk ^= (1 << i);
			cout << (i + 1);
			if (Mk) cout << " ";
			else cout << endl;
		}
	return 0;
}