/*
ID: zapray.1
PROG: frac1
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

int gcd(int a, int b) { return ((a) ? gcd(b%a, a) : b); }

struct frac{ // a/b
	int a, b;
	frac(int _a, int _b) {
		int g = gcd(_a, _b);
		a = _a/g; b = _b/g; 
	}
	bool operator<(const frac &other) const
	{
		return (this->a*other.b) < (this->b*other.a);
	}
};

//#define LOCAL
int main() {
#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("frac1.out", "w", stdout);
	freopen("frac1.in", "r", stdin);
#endif // LOCAL	

	set < frac > s;
	int n;
	cin >> n;
	for (int b = 1; b <= n; b++)
		for (int a = 0; a <= b; a++)
		{
			s.insert(frac(a,b));
		}
	for (auto x : s)
	{
		cout << x.a << "/" << x.b << endl;
	}


	return 0;
}