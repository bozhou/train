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




int main()
{
	int n, k, p, x, y;
	cin >> n >> k >> p >> x >> y;

	vector<int> a;
	int s = 0;
	for (int i = 0; i < k; i++)
	{
		int tmp; cin >> tmp;
		a.push_back(tmp);
		s += tmp;
	}
	if (s > x)
	{
		cout << -1;
		return 0;
	}
	s = x-s;
	if (s<(n-k))
	{
		cout << -1;
		return 0;
	}
	int so = s-n+k;
	s = so;
	for (int i = 0; i < n - k; i++)
	{
		int tmp = 1;
		tmp+=min(s, y-1);
		a.push_back(tmp);
		s -= (tmp-1);
	}
	sort(a.begin(), a.end());
	if (a[n / 2] >= y)
	{
		s = so;
		for (int i = 0; i < n - k; i++)
		{
			int tmp = 1;
			tmp += min(s, y - 1);
			cout << tmp<<" ";
			s -= (tmp - 1);
		}
	}
	else
	{
		cout << -1;
		return 0;
	}

	return 0;
}