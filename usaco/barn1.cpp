/*
ID: zapray.1
PROG: barn1
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

int a[500];
int b[500];

int main() {
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);

	int m,s,c;
	cin >> m >> s>>c;
	for (int i = 0; i < c; i++) cin >> a[i];
	sort(a, a + c);
	int ans = a[c - 1] - a[0]+1;
	for (int i = 0; i < c - 1; i++) b[i] = a[i + 1] - a[i] - 1;
	sort(b, b + c - 1, greater<int>());
	for (int i = 0; i < min(c - 1, m - 1); i++) ans -= b[i];

	cout << ans << endl;
	return 0;
}