/*
ID: zapray.1
PROG: namenum
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

const char m[26] = { '2', '2', '2',
'3', '3', '3',
'4', '4', '4',
'5', '5', '5',
'6', '6', '6', 
'7', '\0', '7', '7',
'8', '8', '8',
'9', '9', '9', '\0' };

int main() {
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);
	ifstream fin("dict.txt");

	string s;
	cin >> s;

	string t;
	int n=0;
	while (fin >> t)
	{
		string x = t;
		for (int i = 0; i < t.size(); i++)
			x[i] = m[t[i]-'A'];
		if (s == x){
			puts(t.data()); n++;
		}
	}
	if (n == 0) puts("NONE");
	return 0;
}