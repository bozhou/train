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
#include <cassert>

using namespace std;
#define MOD 1000000007

typedef long long ll;

void add(int &x, int y)
{
	x += y;
	x %= MOD;
}


int dp[17][17][1 << 16];

class CampLunch {
public:
	int count(int N, int M, vector <string> a) {
		memset(dp, 0, sizeof(dp));

		dp[0][0][0] = dp[0][M][0] = 1;
		for (int i = 1; i <= N; i++)
		{
			for (int s = 0; s < (1 << M); s++)
			{
				int ns = 0;
				if (i == 1) ns = s;
				else
				{
					int ts = 0;
					for (int k = 0; k < M; k++)
						if (s & (1<<k))
							ts |= 1 << (a[i - 2][k] - 'A');
					for (int k = 0; k < M; k++)
						if (ts & (1 << (a[i - 1][k] - 'A')))
						ns |=  1 << k;
				}
				dp[i][0][ns] = dp[i - 1][M][s];
			}
			for (int j = 1; j <= M; j++)
				for (int s = 0; s < (1 << M); s++)
				{
					if (s & (1 << (j - 1)))
					{
						int ns = s;
						ns ^= (1 << (j - 1));
						add(dp[i][j][ns], dp[i][j - 1][s]);
					}
					else
					{
						add(dp[i][j][s], dp[i][j - 1][s]);
						int ns = s;
						ns ^= (1 << (j - 1));
						add(dp[i][j][ns], dp[i][j - 1][s]);
					}
					
					if (j>1 && (s & (3 << (j - 2))) == 0)
						add(dp[i][j][s], dp[i][j - 2][s]);
					
				}
		}

		return dp[N][M][0];
	}
};
