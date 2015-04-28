/*
ID: zapray.1
PROG: pprime
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

bool isprime(int x)
{
	if (x == 2) return 1;
	for (int i = 2; i*i <= x; i++)
		if (x%i == 0) return 0;
	return 1;
}


//#define LOCAL
int main() {
	#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#else
	freopen("pprime.out", "w", stdout);
	freopen("pprime.in", "r", stdin);
	#endif // LOCAL	
	
	int a, b;
	cin >> a >> b;
	
	vector<int> pal;
	int right = 1;
	if (a == 5) pal.push_back(5);

	for (; right < 10000; right += 2)
	{
		if (right % 5 == 0) continue;
		int y=right;
		int x;
		vector<int> d;
		while (y)
		{
			d.push_back(y % 10);
			y /= 10;
		}
		while (d.size() < 5)
		{
			x = 0;
			for (int e : d) x = x * 10 + e;
			for (int i = d.size() - 1; i >= 0; i--) x = x * 10 + d[i];
			if (x >= a && x <= b && isprime(x))
				pal.push_back(x);

			x = 0;
			for (int e : d) x = x * 10 + e;
			for (int i = d.size() - 2; i >= 0; i--) x = x * 10 + d[i];
			if (x >= a && x <= b && isprime(x))
				pal.push_back(x);

			d.push_back(0);
		}
	}
	sort(pal.begin(), pal.end());
	for (int x : pal) cout << x << endl;

	return 0;
}