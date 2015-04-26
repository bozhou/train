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

int m[200005];
vector<int> ch[200005];

int leaves(int x)
{
	m[x] = 0;
	if (ch[x].size() == 0) m[x] = 1;
	else
		for (int y : ch[x])
			m[x] += leaves(y);
	return m[x];
}

int solve(int x, bool level, bool ph)
{
	if (ch[x].size() == 0)
		return 1;

	int ans[2];
	if (level == 0)
	{
		ans[0] = 1; ans[1] = 0;
		for (auto y : ch[x])
		{
			int res = solve(y, !level,ph);

			ans[0] = max(ans[0], m[x]-(m[y]-res) );
			ans[1] += res;
		}
		return ans[ph];
	}
	else
	{
		ans[0] = 1; ans[1] = m[x];
		for (auto y : ch[x])
		{
			int res = solve(y, !level, ph);

			ans[1] = min(ans[1], res);
			ans[0] += (res-1);
		}
		return ans[ph];
	}
}

int main()
{
	int n;
	cin >> n;

	FILL(m, 0);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		ch[a].push_back(b);
	}
	m[1] = leaves(1);
	auto ans0 = solve(1, 0, 0);
	auto ans1 = solve(1, 0, 1);

	printf("%d %d", ans0, ans1);

	return 0;
}