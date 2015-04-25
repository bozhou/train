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


vector<list<int> > f(int n, int s)
{
	vector < list<int> > ans;
	for (int a = s; a*a <= n; a++)
	{
		if (n%a == 0)
		{
			auto v = f(n / a, a);
			for (auto r : v)
			{
				r.push_front(a);
				ans.push_back(r);
			}
		}
	}
	list<int> self;
	self.push_back(n);
	ans.push_back(self);
	return ans;
}


int main()
{
	int n;
	cin >> n;
	while (n)
	{
		auto v = f(n,2);
		cout << v.size()-1<<endl;
		REP(i, 0, v.size() - 1)
		{
			int c = 0;
			for (auto a : v[i])
			{
				if (c++ > 0) printf(" ");
				printf("%d", a);
			}
			cout << endl;
		}
		cin >> n;
	}

	return 0;
}