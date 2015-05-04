/*
ID: zapray.1
PROG: preface
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


//#define LOCAL
int main() {
#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("preface.out", "w", stdout);
	freopen("preface.in", "r", stdin);
#endif // LOCAL	

	int n;
	map<int, vector<int> > m;
	int cnt[7] = { 0 };
	char ch[7]= {'I','V','X','L','C','D','M'};
	m[1] = { 1, 0, 0, 0, 0, 0, 0 };
	m[4] = { 1, 1, 0, 0, 0, 0, 0 };
	m[5] = { 0, 1, 0, 0, 0, 0, 0 };
	m[9] = { 1, 0, 1, 0, 0, 0, 0 };
	m[10] = { 0, 0, 1, 0, 0, 0, 0 };
	m[40] = { 0, 0, 1, 1, 0, 0, 0 };
	m[50] = { 0, 0, 0, 1, 0, 0, 0 };
	m[90] = { 0, 0, 1, 0, 1, 0, 0 };
	m[100] = { 0, 0, 0, 0, 1, 0, 0 };
	m[400] = { 0, 0, 0, 0, 1, 1, 0 };
	m[500] = { 0, 0, 0, 0, 0, 1, 0 };
	m[900] = {0, 0, 0, 0, 1, 0, 1 };
	m[1000] = { 0, 0, 0, 0, 0, 0, 1 };
	
	cin >> n;
	while (n)
	{
		int x = n--;
		while (x)
		{
			for (auto it = m.rbegin(); it != m.rend(); it++)
			{
				while(x >= it->first)
				{
					x -= it->first;
					for (int i = 0; i < 7; i++)
						cnt[i] += it->second[i];
				}
			}
		}
	}
	
	for (int i = 0; i < 7; i++)
		if (cnt[i]>0)
		cout << ch[i] << " " << cnt[i] << endl;



	return 0;
}