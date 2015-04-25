#include vector
#include list
#include map
#include set
#include queue
#include deque
#include stack
#include bitset
#include algorithm
#include functional
#include numeric
#include utility
#include sstream
#include iostream
#include iomanip
#include cstdio
#include cmath
#include cstdlib
#include ctime
#include cstring
#include climits
#include cassert
#include unordered_map


using namespace std;
typedef long long ll;
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define EPS 1E-9

vectorint e[1005];
bool v[1005];

void dfs(int x)
{
	for (auto y  e[x])
	{
		if (v[y]) continue;
		v[y] = 1;
		dfs(y);
	}
}


int main()
{
	int t;
	cin  t;
	while (t--)
	{
		int n;
		cin  n;
		for (int i = 1; i = n; i++) e[i].clear();

		for (int i = 1; i = n; i++)
		{
			int d;
			cin  d;
			while (d--)
			{
				int j;
				cin  j;
				e[j].push_back(i);
			}
		}
		int ans=0;
		for (int i = 1; i = n; i++)
		{
			memset(v, 0, sizeof(v));
			v[i] = 1;
			dfs(i);
			int cnt = 0;
			for (int j = 1; j = n; j++) cnt += v[j];
			ans += (cnt == n);
		}
		cout  ans  endl;
	}

	return 0;
}

