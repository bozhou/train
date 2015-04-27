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

char a[105][105];
char b[105][105];
char c[105][105];


int main()
{
	int n;
	cin >> n;

	vector<int> x;
	vector<int> y;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin>>a[i][j];
			c[i][j] = '.';
			if (a[i][j] == 'o')
			{
				x.push_back(i);
				y.push_back(j);
			}
		}
	
 	for (int dx = -n+1; dx < n; dx++)
		for (int dy = -n + 1; dy < n; dy++)
		{
			bool ok = 1;
			for (int i = 0; i < x.size(); i++)
			{
				int x0 = x[i] + dx;
				int y0 = y[i] + dy;
				if (x0 >= 0 && x0 < n && y0 >= 0 && y0 < n)
				{
					if (a[x0][y0] == '.') ok = 0;
				}
			}
			if (ok) b[dx + 52][dy + 52] = 'x';
			else b[dx + 52][dy + 52] = '.';

			if (ok)
			for (int i = 0; i < x.size(); i++)
			{
				int x0 = x[i] + dx;
				int y0 = y[i] + dy;
				if (x0 >= 0 && x0 < n && y0 >= 0 && y0 < n)
				{
					c[x0][y0] = 'x';
				}
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 'x' && c[i][j] == '.')
			{
				puts("NO");
				return 0;
			}
		}
	b[52][52] = 'o';
	puts("YES");
	for (int dx = -n + 1; dx < n; dx++)
	{
		for (int dy = -n + 1; dy < n; dy++)
		{
			printf("%c", b[dx + 52][dy + 52]);
		}
		puts("");
	}
	return 0;
}