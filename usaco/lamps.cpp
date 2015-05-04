/*
ID: zapray.1
PROG: lamps
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
typedef long long ll;
#define REP(i,s,t) for(int i=(s); i<(t); i++)
#define FILL(x,v) memset(x,v, sizeof(x))


int countbits(int x)
{
	int ans = 0;
	while (x&(-x))
	{
		ans++; x &= (x - 1);
}
	return ans;
}


//#define LOCAL
int main() {
#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("lamps.out", "w", stdout);
	freopen("lamps.in", "r", stdin);
#endif // LOCAL	

	int n,c;
	cin >> n>>c;
	int s[105];
	FILL(s, -1);
	int k;
	while (cin >> k, k != -1) s[k] = 1;
	while (cin >> k, k != -1) s[k] = 0;

	vector<vector<int> > ans;
	for (int x = 0; x < (1 << 4); x++)
	{
		int c0 = countbits(x);
		if (c >= c0 && (c - c0) % 2 == 0)
		{
			vector<int> p(n + 1, 0);
			int i;
			for (i = 1; i <= n; i++)
			{
				p[i] = (1 ^ x ^ ((x >> 1) & i % 2 == 1) ^ 
					((x >> 2) & i % 2 ==0) ^ ((x >> 3)& i%3==1)) & 1;
				if (s[i] >= 0 && s[i] != p[i]) break;
			}

			if (i == n + 1)
				ans.push_back(p);
		}
	}
	if (ans.size()== 0) puts("IMPOSSIBLE");
	else
	{
		sort(ans.begin(), ans.end());
		for (auto v : ans)
		{
			for (int i = 1; i <= n; i++) cout << v[i];
			cout << endl;
		}

	}
	return 0;
}