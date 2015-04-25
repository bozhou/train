#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cassert>
#include <unordered_map>


using namespace std;
typedef long long ll;
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define EPS 1E-9
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))


int a[10005];
int b[10005];

int solve(int a[], int b[], int n, int m)
{
	if (n < m)
		return solve(b, a, m, n);

	int ans = 0;
	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (a[i] == b[j]) {
			i++; j++;
		}
		else if (a[i] < b[j])
		{
			i++; ans++;
		}
		else {
			j++; ans++;
		}
	}
	if (j == m) ans += n - i;
	if (i == n) ans += m - j;
	return ans;

}


int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		REP(i, 0, n) scanf("%d", a + i);
		REP(i, 0, m) scanf("%d", b + i);
		sort(a, a + n);
		sort(b, b + m);
		printf("%d\n", solve(a,b,n,m));
	}


	return 0;
}