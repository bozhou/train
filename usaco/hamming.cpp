/*
ID: zapray.1
PROG: hamming
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

int countbits(int x)
{
	int ans = 0;
	while (x&(-x))
	{
		ans++; x &= (x - 1);
	}
	return ans;
}


bool ok(int k, vector<int> &a, int d)
{
	int ans = 1;
	for (int x : a)
		ans &= (countbits(k^x) >= d);
	return ans;
}

//#define LOCAL
int main() {
#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("hamming.out", "w", stdout);
	freopen("hamming.in", "r", stdin);
#endif // LOCAL	

	int n, b, d;
	cin >> n >> b >> d;

	vector<int> a;
	a.push_back(0);
	int k = 0;
	for (int i = 1; i < n; i++)
	{
		k++;
		while (!ok(k, a, d)) k++;
		a.push_back(k);
	}

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " \n"[(i % 10 == 9)||(i+1==n)];
	}
	return 0;
}