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
#include <unordered_map>


using namespace std;
typedef long long ll;
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define EPS 1E-9
#define INF 1E12
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

typedef pair<int, int> PII;



bool a[505][505];
bool v[505][505];

void dfs(int x, int y)
{
	if (v[x][y]) return;
	v[x][y] = 1;
	if (a[x - 1][y]) dfs(x - 1, y);
	if (a[x][y - 1]) dfs(x, y - 1);
	if (a[x + 1][y]) dfs(x + 1, y);
	if (a[x][y + 1]) dfs(x, y + 1);
	return;
}


int main()
{
	int r, c;
	cin >> r >> c;
	FILL(a, 0);
	FILL(v, 0);
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
		{
			char ch;
			cin >> ch;
			a[i][j] = (ch == '.');
		}
	int x, y;
	cin >> x >> y;
	int p, q;
	cin >> p >> q;
	dfs(x, y);

	if (a[p][q] == 1)
	{
		int cnt = 0;
		cnt += v[p - 1][q] + v[p][q - 1] + v[p + 1][q] + v[p][q + 1];
		
		if (abs(p - x) + abs(q - y) == 1 && a[x][y])
		{
			if (cnt) cout << "YES";
			else cout << "NO";
		}
		else if (v[p][q] == 0 || cnt < 2)
		{
			cout << "NO";
		}
		else cout << "YES";
	}
	else
	{
		int cnt = 0;
		cnt += v[p - 1][q] + v[p][q - 1] + v[p + 1][q] + v[p][q + 1];
		if (cnt) cout << "YES";
		else cout << "NO";
	}

	return 0;
}