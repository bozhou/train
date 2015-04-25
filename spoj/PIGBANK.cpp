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

int dp[10005];
int w[505];
int p[505];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int e,f;
		cin >> e >>f;
		f -= e;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) scanf("%d%d", p + i, w + i);
		
		for (int i = 0; i <= f; i++) dp[i] = INT_MAX;
		dp[0] = 0;
		for (int c = 0; c <= f; c++)
		{
			if (dp[c] < INT_MAX)
				for (int j = 0; j < n; j++)
				{
					if (c + w[j] > f) continue;
					if (dp[c] + p[j] < dp[c + w[j]])
						dp[c + w[j]] = dp[c] + p[j];
				}
		}
		if (dp[f] < INT_MAX)
			printf("The minimum amount of money in the piggy-bank is %d.\n", dp[f]);
		else puts("This is impossible.");

	}

	return 0;
}