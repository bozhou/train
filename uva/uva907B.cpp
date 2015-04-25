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
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))


ll dp[666][333];
ll a[666];
ll s[666];

int main()
{

	int n, k;
	while (cin >> n >> k)
	{
		if (k > n) k = n;
		n++;
		REP(i, 0, n){
			scanf("%lld", a + i);
			if (i == 0) s[i] = a[i];
			else s[i] = s[i - 1] + a[i];
		}
		memset(dp, 0, sizeof(dp));

		REP(i, 0, n) dp[i][0] = s[i];

		REP(c, 1, k + 1)
			REP(i, 0, n)
		{
			dp[i][c] = dp[i][c - 1];
			for (int j = i - 1; j >= 0; j--)
			{
				ll r = s[i] - s[j];
				dp[i][c] = min(dp[i][c], max(dp[j][c - 1], r));
			}
		}
		cout << dp[n - 1][k]<<endl;
	}
	return 0;
}