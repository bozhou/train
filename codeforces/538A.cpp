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


int main()
{
	string s;
	cin >> s;
	string t = "CODEFORCES";
	int n = s.size();
	int m = t.size();

	if (n>=m)
	for (int i = 0;  i<=m; i++)
	{
		string x;
		x = s.substr(0, i) + s.substr(i + n - m);
		if (x == t) {
			puts("YES"); return 0;
		}
	}

	puts("NO");
	return 0;
}