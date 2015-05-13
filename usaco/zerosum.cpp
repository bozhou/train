/*
ID: zapray.1
PROG: zerosum
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
#include <unordered_set>

using namespace std;
typedef long long ll;
#define REP(i,s,t) for(int i=(s); i<(t); i++)
#define FILL(x,v) memset(x,v, sizeof(x))

int calc(vector<int> &s)
{
	int n = s.size() + 1;
	queue <int> op;
	stack <int> v;
	int x = 0;

	for (int i = 1; i < n; i++)
	{
		x += i;
		if (s[i - 1] != 0)
		{
			op.push(x);
			x = 0;
		}
		else
		{
			x *= 10;
		}
	}
	op.push(x+n);
	
	int ans = op.front(); op.pop();
	for (int ch : s)
	{
		if (ch == 0) continue;
		if (ch == 1)
		{
			ans += op.front(); op.pop();
		}
		else
		{
			ans -= op.front(); op.pop();
		}
	}
	
	return ans;
}

bool addone(vector<int> &s, int base)
{
	int i = s.size() - 1;
	while (i >= 0)
	{
		if (s[i] == base - 1)
		{
			s[i] = 0;
			i--;
		}
		else break;
	}
	if (i<0) return 0;
	s[i]++;
	return 1;
}

//#define LOCAL
int main() {
#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("zerosum.out", "w", stdout);
	freopen("zerosum.in", "r", stdin);
#endif // LOCAL	

	int n;
	cin >> n;
	char chs[3] = { ' ', '+', '-' };
	vector <int> s;
	for(int i=0; i<n-1; i++) s.push_back(0);
	
	do
	{
		if (calc(s) == 0)
		{
			for (int i = 1; i < n; i++)
			{
				cout << i << chs[s[i - 1]];
			}
			cout << n << "\n";
		}
	} while (addone(s, 3));

}