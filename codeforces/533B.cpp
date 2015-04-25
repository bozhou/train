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

typedef pair<ll, ll> PLL;
#define INF 1E12

int v[200005]; 
vector<int> ch[200005];

PLL solve(int i)
{
	if (ch[i].size() == 0) return make_pair(0, -INF);

	int k = 0;
	PLL ans(0,-INF);
	for (auto c : ch[i])
	{
		auto sc = solve(c);

		PLL nans;
		nans.first = max( max(ans.first + sc.first, ans.second + sc.second), ans.second + v[c] + sc.first);
		nans.second = max( max(ans.first + sc.second, ans.second + sc.first), ans.first + v[c] + sc.first);
		ans = nans;
		k++;
	}
	return ans;
}


int main()
{
	int n;
	cin >> n;
	REP(i,0,n)
	{
		int father;
		cin >> father >> v[i];
		if (father>0)
			ch[father-1].push_back(i);
	}

	auto sc = solve(0);
	cout << max(  sc.second,  v[0] + sc.first)<<endl;


	return 0;
}