/*
ID: zapray.1
PROG: sort3
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
#define REP(i,s,t) for(int i=(s); i<(t); i++)
#define FILL(x,v) memset(x,v, sizeof(x))

int n;
int cnt[4];
char a[1005];

//#define LOCAL
int main() {
#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("sort3.out", "w", stdout);
	freopen("sort3.in", "r", stdin);
#endif // LOCAL	

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		cnt[a[i]]++;
	}
	int ans = 0;
	int cnt12, cnt13;
	cnt12 = cnt13 = 0;
	for (int i = 0; i < cnt[1]; i++)
	{
		ans += (a[i]>1);
		cnt12 += (a[i] == 2);
		cnt13 += (a[i] == 3);
	}
	for (int i = cnt[1]; i < cnt[1] + cnt[2]; i++)
	{
		if (a[i] == 1)
		{
			if (cnt12) cnt12--;
			else ans++;
		}
		ans += (a[i] == 3);
	}
	cout << ans << endl;


	return 0;
}