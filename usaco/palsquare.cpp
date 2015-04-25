/*
ID: zapray.1
PROG: palsquare
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

bool ispalin(string x)
{
	int i = 0, j = x.size() - 1;
	while (i <= j)
	{
		if (x[i] == x[j]) { i++; j--; }
		else break;
	}
	return (i > j);
}


string to_base(int x, int b)
{
	string ans;
	if (x == 0) return string("0");

	while (x)
	{
		int y = x%b;
		if (y<10) ans.push_back('0'+y);
		else ans.push_back('A' + y - 10);
		x = x / b;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);

	int b;
	cin >> b;
	for (int i = 1; i <= 300; i++)
	{
		string x, x2;
		x2 = to_base(i*i, b);
		if (ispalin(x2))
		{
			x = to_base(i, b);
			cout << x << " " << x2 << endl;
		}
	}

	return 0;
}