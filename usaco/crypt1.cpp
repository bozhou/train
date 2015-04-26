
ID zapray.1
PROG crypt1
LANG C++11              

#include iostream
#include fstream
#include cstdlib
#include cstdio
#include cstring
#include string
#include cmath
#include algorithm
#include functional
#include vector
#include map
#include queue
#include set
#include stack
#include climits
#include cassert

using namespace std;
#define REP(i,s,t) for(int i=(s); i(t); i++)

int n;
int v[10];
bool h[10];


bool test(int x)
{
	while (x)
	{
		int d=x % 10;
		if (h[d] == 0) return 0;
		x = 10;
	}
	return 1;
}




int main() {
	freopen(crypt1.in, r, stdin);
	freopen(crypt1.out, w, stdout);
	freopen(test.in, r, stdin);
	freopen(test.out, w, stdout);

	cin  n;
	memset(h, 0, sizeof(h));
	REP(i, 0, n)
	{
		cin  v[i];
		h[v[i]] = 1;
	}
	int ans=0;
	int a, b, c, d, e;
	REP(a, 0, n) REP(b, 0, n) REP(c, 0, n)
	{
		REP(d, 0, n) REP(e, 0, n)
		{
			int x = v[a]  100 + v[b]  10 + v[c];
			int y[3];
			y[0] = xv[e];
			y[1] = xv[d];
			y[2] = y[0] + 10  y[1];
			bool ok = (y[0]  1000) && (y[1]  1000) && (y[2]  10000)
				&& test(y[0]) && test(y[1]) && test(y[2]);
			ans += ok;
		}
	}

	cout  ans  endl;
	
	return 0;
}