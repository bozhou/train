/*
ID: zapray.1
PROG: milk
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
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <climits>
#include <cassert>

using namespace std;

pair<int,int> p[5005];

int main() {
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) scanf("%d%d", &(p[i].first), &(p[i].second));
	sort(p, p+m);
	int i = 0;
	int ans = 0;
	while (n)
	{
		if (n >= p[i].second)
		{
			ans += p[i].first*p[i].second;
			n -= p[i].second;
			i++;
		}
		else
		{
			ans += p[i].first*n;
			n = 0;
			i++;
		}
	}
	cout << ans << endl;
	return 0;
}