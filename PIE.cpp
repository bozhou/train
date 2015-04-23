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

int r2[10005];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, f;
		cin >> n >> f;
		f++;
		double l, h = 0;
		for (int i = 0; i < n; i++)
		{
			int r;
			scanf("%d", &r);
			r2[i]=r*r;
			h = (h<r2[i])? r2[i]: h;
		}
		l = h/f;
		while (abs(h - l) > 1E-7)
		{
			double m = (h + l) / 2;
			int c = 0;
			for (int i = 0; i < n; i++) c += (int)(r2[i] / m) ;
			if (c >= f)
			{
				l = m;
			}
			else h = m;
		}
		printf("%.4f\n", l*3.14159265358979323846);
	}



	return 0;
}