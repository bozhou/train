/*
ID: zapray.1
PROG: prefix
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


bool dp[200006];


//#define LOCAL
int main() {
#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("prefix.out", "w", stdout);
	freopen("prefix.in", "r", stdin);
#endif // LOCAL	

	set<string> dict;

	string x;
	while (cin >> x)
	{
		if (x != ".")
			dict.insert(x);
		else break;
	}
	string t;
	while (cin >> x)
		t += x;
	dp[0] = 1;
	int maxi = 0;
	for (int i = 0; i <= t.size(); i++)
	{
		if (dp[i])
		{
			maxi = i;
			for (int l = 1; l <= 10; l++)
			{
				string tmp = t.substr(i, l);
				if (dict.count(tmp)) dp[i + l]=1;
			}
		}
	}
	cout << maxi << endl;

	return 0;
}