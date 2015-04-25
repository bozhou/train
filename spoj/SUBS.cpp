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


bool ok(string &x, string &y, int k)
{
	int j = 0; 
	bool ans = 1;
	for (int i = 0; i < x.size() && ans; i++)
	{
		for (int p = 0; p < k && ans; p++)
		{
			while (j < y.size() && x[i]!=y[j])
			{
				j++;
			}
			ans = (j < y.size());
			j++;
		}
	}
	return ans;
}


int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		string x,y;
		cin >> x >> y;
		assert(x.size()>0);
		int l = 0, r = y.size() / x.size();
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (ok(x, y, m))
				l = m + 1;
			else r = m - 1;
		}
		
		cout << r << endl;
	}

	return 0;
}