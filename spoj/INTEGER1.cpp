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


using namespace std;
typedef long long ll;
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define EPS 1E-9


bool T[10005];

vector< pair<ll, ll> > factor(ll x)
{
	vector< pair<ll, ll> > ans;
	for (ll i = 2; i*i <= x; i++)
	{
		if (x%i) continue;
		ll cnt = 0;
		while (x%i == 0) { cnt++; x /= i; }
		ans.push_back(make_pair(i, cnt));
	}
	if (x>1) ans.push_back(make_pair(x, 1));
	return ans;
}

ll gcd(ll a, ll b)
{
	if (a == 0) return b;
	else return gcd(b%a, a);
}

ll power(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1ll) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}


ll cnt(ll a, ll b, int k)
{
	if (a > b) return 0;
	if (k == 1)
	{
		ll ans = 0;
		if (b <= 10000)
		{
			for (ll x = a; x <= b; x++)
				ans += T[x];
			return ans;
		}

		ans = b - a + 1;
		for (int kk = 2; kk < 63; kk++)
		{
			ans -= cnt(a, b, kk);
		}
		return ans;
	}
	else
	{
		ll p = floor(pow(a, 1.0 / k));
		ll q = floor(pow(b, 1.0 / k) +1E-9);  // WA IF 1E-12, WTF!?
		while (power(p, k) < a) p++;
		while (power(q, k) > b) q--;

		return cnt(p, q, 1);
	}
}


int main()
{
	memset(T, 0, sizeof(T));

	for (int x = 2; x <= 10000; x++)
	{
		vector< pair<ll, ll> >  v = factor(x);

		bool ok = 0;
		if (v.size() == 1) ok = (v[0].second == 1);
		else
		{
			ll g = v[0].second;
			for (int i = 0; i < v.size(); i++)
			{
				g = gcd(g, v[i].second);
			}
			ok = (g == 1);
		}
		T[x] = ok;
	}



	ll a, b;
	cin >> a >> b;
	while (a && b)
	{
		ll ans = 0;
		ll c1 = b - a + 1;
		for (int k = 2; k < 63; k++)
		{

			ll ck = cnt(a, b, k);
			c1 -= ck;
			ans += ck*k;

		}
		ans += c1;
		cout << ans << endl;

		cin >> a >> b;
	}

	return 0;
}