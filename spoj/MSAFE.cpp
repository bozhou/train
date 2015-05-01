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
#define INF 1E12
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

typedef pair<int, int> PII;

int n;
int M = 10000000;
ll p[200005];


int main()
{
	cin >> n;
	int t;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &t);
		p[i*2] = t; 
		p[i * 2 + 1] = t+M;
	}
	p[2 * n] = 0;
	sort(p, p + 2 * n+1);
	for (int i = 1; i <= 2 * n; i++)
		p[i] += p[i - 1];
	
	ll ans = LLONG_MAX;
	for (int i = 1; i <= n; i++)
	{
		int j = i + n-1;
 		int m1 = (i + j) / 2;
		int m2 = (i + j+1) / 2;
		ans = min(ans, p[j] - p[m2-1] - (p[m1] - p[i-1]));
	}

	cout << ans << endl;


	return 0;
}