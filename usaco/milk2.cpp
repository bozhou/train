/*
ID: zapray.1
PROG: milk2
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

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector< pii > vii;

vii t;

int main() {
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		t.push_back(pii(x, y));
	}
	sort(t.begin(), t.end());

	int ans1=0, ans2=0;

	int start = t[0].first; 
	int end = t[0].second;
	ans1 = end - start;
	
	for (int i = 1; i < n; i++)
	{
		if (t[i].first <= end) {
			end = max(end, t[i].second);
		}
		else{
			ans2 = max(t[i].first - end, ans2);
			start = t[i].first;
			end = t[i].second;
		}

		ans1 = max(end - start, ans1);
	}
	
	cout << ans1 << " " << ans2 << endl;

	return 0;
}