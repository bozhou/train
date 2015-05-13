#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cassert>


using namespace std;
typedef long long ll;
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define EPS 1E-9
#define INF 1E12
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

typedef pair<int, int> PII;

int d[3005][3005];

vector<int> e[3005];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	int s1, t1, l1;
	int s2, t2, l2;
	cin >> s1 >> t1 >> l1;
	cin >> s2 >> t2 >> l2;

	FILL(d, -1);
	for (int i = 1; i <= n; i++)
	{
		d[i][i] = 0;
		queue<int> q;
		q.push(i);
		while (!q.empty())
		{
			int j = q.front(); q.pop();
			for (int k : e[j])
				if (d[i][k]<0){
					q.push(k);
					d[i][k] = d[i][j] + 1;
				}
		}
	}
	if (d[s1][t1] > l1 || d[s2][t2] > l2)
	{
		cout << -1 << endl;
		return 0;
	}

	int r = d[s1][t1] + d[s2][t2];
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= n; y++)
		{
			if (d[x][y] + d[s1][x] + d[y][t1] <= l1 && d[x][y]+ d[s2][x] + d[y][t2]<=l2)
				r = min(r, d[x][y] + d[s1][x] + d[y][t1] + d[s2][x] + d[y][t2]);
			if (d[x][y] + d[s1][y] + d[x][t1] <= l1 && d[x][y] + d[s2][x] + d[y][t2] <= l2)
				r = min(r, d[x][y] + d[s1][y] + d[x][t1] + d[s2][x] + d[y][t2]);
		}
	cout << m - r << endl;

	return 0;
}