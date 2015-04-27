/*
ID: zapray.1
PROG: wormhole
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

vector<pair<int,int> > pt;
int n;
vector<vector<int> > e;
vector<pair<int, int> > pr;
int ans;

vector<bool> v;
vector<bool> onstack;

bool dfs(int i, vector<vector<int> >& ne)
{
	if (v[i]) 
		if (onstack[i]) return 0;
		else return 1;
	else
	{
		bool ok = 1;
		v[i] = 1;
		onstack[i] = 1;
		for (int next : ne[i])
		{
			ok &= dfs(next, ne);
		}
		onstack[i] = 0;
		return ok;
	}
}

void solve(int i, set<int> s)
{
	if (i == n / 2)
	{
		auto ne = e;
		for (auto p : pr)
		{
			ne[p.first].push_back(p.second + n);
			ne[p.second].push_back(p.first + n);
		}
		v.clear();
		v.resize(2*n);

		bool ok = 1;
		for (int k = 0; k < n; k++)
		{
			ok &= dfs(k,ne);
		}
		ans += (!ok);
	}
	else
	{
		int a = *s.begin();
		s.erase(a);
		for (int b : s)
		{
			set<int> t(s);
			t.erase(b);
			pr.push_back(make_pair(a, b));
			solve(i + 1, t);
			pr.pop_back();
		}
		s.insert(a);
	}
}

int main() {
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	cin >> n;
	ans = 0;
	pt.resize(n);
	for (int i = 0; i < n; i++) cin >> pt[i].second>>pt[i].first;
	sort(pt.begin(), pt.end());

	e.resize(n*2);
	for (int i = 0; i < pt.size() - 1; i++)
		if (pt[i].first == pt[i + 1].first)
			e[i + n].push_back(i+1);

	set<int> s;
	onstack.clear();
	onstack.resize(2 * n);
	for (int i = 0; i < n; s.insert(i++));
	solve(0,s);
	cout << ans << endl;

	return 0;
}