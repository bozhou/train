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


bool p(int n, int i)
{
	while (i--)
	{
		n /= 10;
	}
	return (n % 10);
}

int pw(int b, int x)
{
	int a = 1;
	while (x--) a *= b;
	return a;
}

int main()
{
	vector<int> v;
	int ans = 0;
	int n;
	cin >> n;
	while (n)
	{
		int M = 0;
		for (int i = 0; i <= 6; i++)
		{
			if (p(n,i)) M += pw(10,i);
		}
		ans++;
		n -= M;
		v.push_back(M);
	}
	cout << ans << endl;
	for (int x : v) cout << x << " ";

	return 0;
}