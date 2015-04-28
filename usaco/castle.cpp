/*
ID: zapray.1
PROG: castle
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

#define MAXN 

//begin union find 
int prnt[2555];
int rnk[2555];

void MakeSet(int x)
{
	prnt[x] = x;
	rnk[x] = 0;
}

int Find(int x)
{
	if (prnt[x] != x)
		prnt[x] = Find(prnt[x]);
	return prnt[x];
}

void Union(int x, int y)
{
	int xRoot = Find(x);
	int yRoot = Find(y);
	if (xRoot == yRoot) return;

	if (rnk[xRoot] < rnk[yRoot])
		prnt[xRoot] = yRoot;
	else if (rnk[xRoot] > rnk[yRoot])
		prnt[yRoot] = xRoot;
	else {
		prnt[yRoot] = xRoot;
		rnk[xRoot]++;
	}
}

//#define LOCAL
int main() {
#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("castle.out", "w", stdout);
	freopen("castle.in", "r", stdin);
#endif // LOCAL	


	int dx[4] = {0,-1,0,1};
	int dy[4] = {-1,0,1,0};

	int r, c;
	cin >> c >> r;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			int ind = i*c + j;
			MakeSet(ind);
		}

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			int w;
			cin >> w;
			int ind = i*c +j;
			for (int p = 0; p < 4; p++)
			{
				if ((~w) & (1 << p))
				{
					int ni = i + dx[p];
					int nj = j + dy[p];
					if (ni >= 0 && ni < r && nj >= 0 && nj < c)
					{
						int nind = ni*c + nj;
						Union(ind, nind);
					}
				}
			}
		}

	map<int, int> rooms;
	int max_r = 1;
	for (int i = 0; i < r*c; i++)
	{
		rooms[Find(i)]++;
		max_r = max(max_r, rooms[Find(i)]);
	}
	cout << rooms.size()<<endl;
	cout << max_r<<endl;

	int max_u = max_r;
	int max_wall[3];


	for (int j = 0; j < c; j++)
		for (int i = r - 1; i >= 0; i--)
			for (int p = 1; p <= 2; p++)
			{
				int ind = i*c + j;
				int ni = i + dx[p];
				int nj = j + dy[p];
				if (ni >= 0 && ni < r && nj >= 0 && nj < c)
				{
					int nind = ni*c + nj;
					if (Find(ind) != Find(nind)
						&& rooms[Find(ind)] + rooms[Find(nind)] > max_u)
					{
						max_u = rooms[Find(ind)] + rooms[Find(nind)];
						max_wall[0] = i;
						max_wall[1] = j;
						max_wall[2] = p;
					}
				}
			}
	cout << max_u<<endl;
	cout << max_wall[0]+1 << " " << max_wall[1]+1 << " " << ((max_wall[2]==1)?"N":"E") << endl;

}