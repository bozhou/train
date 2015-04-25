/*
ID: zapray.1
PROG: transform
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

char m1[15][15];
char m2[15][15];

char m[15][15];

int n;

bool issame()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (m[i][j] != m2[i][j]) return 0;
		}
	return 1;
}

void flipH()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n/2; j++)
		{
			swap(m[i][j], m[i][n-1-j]);
		}
}

void flipV()
{
	for (int i = 0; i < n/2; i++)
		for (int j = 0; j < n; j++)
		{
			swap(m[i][j], m[n-1-i][j]);
		}
}


void flipD()
{
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
		{
			swap(m[i][j], m[j][i]);
		}
}

void rotate()
{
	flipV();
	flipD();
}


int main() {
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);

	cin >> n;
	int ans=7;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> m1[i][j];
			m[i][j]= m1[i][j];
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> m2[i][j];

	if (issame()) { ans =min(ans,6); }

	flipH();
	if (issame()) { ans = min(ans, 4); }
	for (int i = 1; i < 4; i++)
	{
		rotate();
		if (issame()) { ans = min(ans, 5); }
	}
	rotate();
	flipH();

	for (int i = 1; i < 4; i++)
	{
		rotate();
		if (issame()) { ans = min(ans, i); }
	}

	cout << ans << endl;
	return 0;
}