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

ll mergesort(vector<int>::iterator lo, vector<int>::iterator hi)
{
	if (hi - lo <= 1) return 0;

	auto  m = lo + (hi - lo) / 2;
	ll ans = mergesort(lo, m) + mergesort(m, hi);
	auto i = lo, j = m;
	vector<int> temp;
	while (i != m && j != hi)
	{
		if (*i <= *j){
			temp.push_back(*(i++));
			ans += j - m;
		}
		else temp.push_back(*(j++));
	}
	while (i != m){
		temp.push_back(*(i++));
		ans += j - m;
	}
	while (j != hi) temp.push_back(*(j++));
	for (int i = 0; i < temp.size(); i++) *(lo + i) = temp[i];
	return ans;
}


int main()
{

	int n;
	cin >> n;

	map<int, int> m;
	while (n--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (m[a] == 0) m[a] = a;
		if (m[b] == 0) m[b] = b;
		swap(m[a], m[b]);
	}
	vector<int> v;
	vector<int> u;
	for (auto x : m)
	{
		v.push_back(x.first);
		u.push_back(x.second);
	}
	ll ans = 0;
	n = v.size();
	for (int i = 0; i < n; i++)
	{
		int j = lower_bound(v.begin(), v.end(), u[i]) - v.begin();
		if (v[i] < u[i])
			ans += (u[i] - v[i] - 1) - (j - i - 1);
		else if (v[i] > u[i])
			ans += (v[i] - u[i] - 1) - (i - j - 1);
	}
	ans += mergesort(u.begin(), u.end());
	cout << ans;
	return 0;
}