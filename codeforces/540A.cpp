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


int dist(int a, int b)
{
	if (a > b) return dist(b, a);
	else return min(b - a, a + 10 - b);
}


int main()
{
	int n;

	cin >> n;
	string s, t;
	cin >> s >> t;
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += dist(s[i] - '0', t[i] - '0');

	cout << ans;
	return 0;
}