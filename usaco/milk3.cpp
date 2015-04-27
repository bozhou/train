/*
ID: zapray.1
PROG: milk3
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

int A, B, C;
int toidx(int a, int b, int c)
{
	return 	a*(B + 1)*(C + 1) + b*(C + 1) + c;
}

void toabc(int x, int &a, int &b, int &c)
{
	c = x % (C + 1);
	b = (x - c) / (C + 1) % (B + 1);
	a = x / ((B + 1)*(C + 1));
	return;
}


bool visit[10000];
bool vc[25];

void dfs(int x)
{
	if (!visit[x])
	{
		visit[x] = 1;
		int a, b, c;
		toabc(x, a, b, c);
		if (a == 0) vc[c] = 1;

		int aa, bb, cc;

		// a->b
		aa = a - min(B - b, a);
		bb = b + (a - aa);
		cc = c;
		dfs(toidx(aa, bb, cc));

		// a->c
		aa = a - min(C - c, a);
		bb = b;
		cc = c + (a - aa);
		dfs(toidx(aa, bb, cc));

		// b->a
		bb = b - min(A - a, b);
		aa = a + (b - bb);
		cc = c;
		dfs(toidx(aa, bb, cc));

		// b->c
		bb = b - min(C - c, b);
		aa = a;
		cc = c + (b - bb);
		dfs(toidx(aa, bb, cc));

		// c->a
		cc = c - min(A - a, c);
		bb = b ;
		aa = a + (c-cc);
		dfs(toidx(aa, bb, cc));

		// c->b
		cc = c - min(B - b, c);
		bb = b + (c - cc);
		aa = a ;
		dfs(toidx(aa, bb, cc));
	}
}

//#define LOCAL
int main() {
	#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#else
	freopen("milk3.out", "w", stdout);
	freopen("milk3.in", "r", stdin);
	#endif // LOCAL	
	cin >> A >> B >> C;
	
	dfs(toidx(0, 0, C));

	for (int i = 0; i < C; i++)
		if (vc[i]) printf("%d ",i);
	cout <<C<< endl;
	return 0;
}