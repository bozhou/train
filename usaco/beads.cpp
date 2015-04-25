/*
ID: zapray.1
PROG: beads
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
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <climits>
#include <cassert>
using namespace std;




int main() {
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);

	int n;
	cin >> n;
	char c0, c, d;
	vector<int> v;
	vector<char> ch;
	cin >> c0;
	
	int x = 1;
	c = c0;
	n--;
	while (n--)
	{
		cin >> d;
		if (d == c) x++;
		else {
			v.push_back( x );
			ch.push_back( c );
			x = 1; c = d;
		}
	}
	if (d == c0 && v.size()>0)
	{
		v[0] += x;
	}
	else {
		v.push_back(x);
		ch.push_back(d);
	}

	vector<int> v2;
	n = v.size();
	for (int i = 0; i < n; i++)
	{
		if (ch[i] == 'w' && ch[(i - 1 + n) % n] == ch[(i + 1 + n) % n])
			ch[i] = ch[(i + 1 + n) % n];
	}
	for (int i = n-1; i > 0; i--)
	{
		if (ch[i] == ch[i - 1]) {
			v[i - 1] += v[i];
			v[i] = 0;
		}
	}
	for (int i = n - 1; i > 0 ; i--)
	{
		if (v[i])
		{
			if (ch[i] == ch[0]) {
			v[0] += v[i];  v[i] = 0; 
			}
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (v[i]>0) v2.push_back(ch[i]=='w'?-v[i]:v[i]);
	}


	if (v2.size() == 1) {
		cout << abs(v2[0]) << endl; return 0;
	}


	int ans = 1;
	for (int i = 0; i < v2.size(); i++)
	{
		int pos = 0;
		int cnt = 0; 
		for (int k = 0; k < 5; k++)
		{
			int j = i + k;
			if (j >= v2.size()){ 
				j -= v2.size(); 
				if (j >= i) break;
			}
			if (v2[j] > 0)
				if (pos == 2) break;
				else
				{
					pos++;
					cnt+=v2[j];
				}
			else cnt -= v2[j];
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}