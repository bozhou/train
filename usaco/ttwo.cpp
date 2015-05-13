/*
ID: zapray.1
PROG: ttwo
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

//#define LOCAL
int main() {
#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("ttwo.out", "w", stdout);
	freopen("ttwo.in", "r", stdin);
#endif // LOCAL	

	bool m[12][12];
	FILL(m, 0);
	int x, y, a, b;

	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			char ch;
			cin >> ch;
			m[i][j] = (ch != '*');
			if (ch == 'F') {
				x = i; y = j;
			}
			if (ch == 'C') {
				a = i; b = j;
			}
		}

	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int d1 = 0, d2 = 0;

	for (int t = 0; t < 160010; t++)
	{

		if (x == a && y == b)
		{
			cout << t << endl;
			return 0;
		}

		if (m[x + dx[d1]][y + dy[d1]])
		{
			x += dx[d1];
			y += dy[d1];
		}
		else d1 = (d1 + 1) % 4;


		if (m[a + dx[d2]][b + dy[d2]])
		{
			a += dx[d2];
			b += dy[d2];
		}
		else d2 = (d2 + 1) % 4;
	}

	cout << 0<<endl;
	return 0;
}