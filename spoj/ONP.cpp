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


using namespace std;
typedef long long ll;
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define EPS 1E-9


string s;
int p[405];

map<char,int> order;

string solve(int l, int r)
{
	if (p[l] == r)
		return solve(l + 1, r - 1);
	if (l == r) return s.substr(l, 1);

	int b = 0;
	int x = -1;
	for (int i = l; i <= r; i++)
	{
		if (s[i] == '(') b++;
		else if (s[i] == ')') b--;
		else if (b == 0)
		{
			if (order.count(s[i]))
				if (x <= 0)  x = i;
				else x = (order[s[i]] < order[s[x]]) ? i : x;
		}
	}
	return solve(l, x - 1) + solve(x + 1, r) + s.substr(x,1);
}



int main()
{
	order['+'] = 1;
	order['-'] = 2;
	order['*'] = 3;
	order['/'] = 4;
	order['^'] = 5;


	int t;
	cin >> t;
	while (t--)
	{
		cin >> s;
		memset(p,0,sizeof(p));
		stack<int> t;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(') {
				t.push(i);
			}
			else if (s[i] == ')')
			{
				int v = t.top();
				t.pop();
				p[v] = i;
				p[i] = v;
			}
		}
		cout << solve(0, s.size() - 1) <<endl;

	}

	return 0;
}