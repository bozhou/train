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


bool p(int n, int i)
{
	while (i--)
	{
		n /= 10;
	}
	return (n % 10);
}

int pw(int b, int x)
{
	int a = 1;
	while (x--) a *= b;
	return a;
}

int main()
{
	int n,m;
	cin >> n>>m;

	int d1, h1, d2, h2;
	scanf("%d%d", &d1, &h1);
	m--;
	int ans = 0;
	int h0 = h1 + (d1 - 1);
	ans = max(ans, h0);

	while (m--)
	{
		scanf("%d%d", &d2, &h2);
		if (abs(h2 - h1) > (d2 - d1))
		{
			puts("IMPOSSIBLE");
			return 0;
		}
		if (h1 <= h2)
		{
			int x = h2 - h1 + d1;
			int y = (x + d2) / 2;
			ans = max(ans, y - d1 + h1);
		}
		else
		{
			int x = d2 - (h1 - h2);
			int y = (d1 + x) / 2;
			ans = max(ans, y - d1 + h1);
		}
		h1 = h2;
		d1 = d2;
	}
	h0 = h1 + n - d1;
	ans = max(ans, h0);

	cout << ans;

	return 0;
}