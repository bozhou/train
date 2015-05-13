/*
ID: zapray.1
PROG: concom
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


int c[105][105];
int ss[105][105];

void solve(int x)
{
	queue<int> q;
	vector<bool> inq(105, 0);
	for (int i = 1; i <= 100; i++)
	{
		if (i == x) continue;
		ss[x][i] = c[x][i];
		if (ss[x][i] > 50)
		{
			q.push(i); inq[i] = 1;
		}
	}

	while (!q.empty())
	{
		int y = q.front();  q.pop();
		for (int z = 1; z <= 100; z++)
		{
			if (z == y || z == x) continue;
			ss[x][z] += c[y][z];

			if (ss[x][z] > 50  && !inq[z])
			{
				q.push(z); inq[z] = 1;
			}
		}
	}

}

//#define LOCAL
int main() {
#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("concom.out", "w", stdout);
	freopen("concom.in", "r", stdin);
#endif // LOCAL	

	int n;
	cin >> n;

	FILL(c, 0);
	FILL(ss, 0);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		scanf("%d", &c[a][b]);
	}

	for (int i = 1; i <= 100; i++)
		solve(i);

	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
		{
			if (i != j && ss[i][j] > 50)
				printf("%d %d\n", i, j);
		}


	return 0;
}