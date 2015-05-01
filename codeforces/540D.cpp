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


vector<double> dp[105][105][105];

void solve(int a, int b, int c)
{
	if (dp[a][b][c][0] + dp[a][b][c][1] + dp[a][b][c][2] > 0) return;

	if (a && b && c)
	{
		solve(a - 1, b, c);
		solve(a, b - 1, c);
		solve(a, b, c - 1);
		for (int i = 0; i < 3; i++)
		{
			dp[a][b][c][i] += dp[a - 1][b][c][i] * (a*c) / (a*c + b*c + a*b);
			dp[a][b][c][i] += dp[a][b - 1][c][i] * (a*b) / (a*c + b*c + a*b);
			dp[a][b][c][i] += dp[a][b][c - 1][i] * (b*c) / (a*c + b*c + a*b);

		}
	}
	return;
}


int main()
{
	FILL(dp, 0);
	int a, b, c;
	cin >> a >> b >> c;

	for (int i = 0; i <= a; i++)
		for (int j = 0; j <= b; j++)
			for (int k = 0; k <= c; k++)
				dp[i][j][k] = vector <double>(3, 0);
	for (int i = 1; i <= a; i++)
		for (int j = 0; j <= b; j++)
			dp[i][j][0][0] = 1.0;

	for (int j = 1; j <= b; j++)
		for (int k = 0; k <= c; k++)
			dp[0][j][k][1] = 1.0;
	for (int k = 1; k <= c; k++)
		for (int i = 0; i <= a; i++)
			dp[i][0][k][2] = 1.0;


	solve(a, b, c);
	for (int i = 0; i < 3; i++)
		printf("%.12lf ", dp[a][b][c][i]);


	return 0;
}