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

string s;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> s;
		int n = s.size();

		bool g=0;
		for (int i = (n-1)/2; i>=0; i--)
		{
			int p = i;
			int q = n - 1 - i;
			if (s[p] == s[q]) continue;
			else
			{
				g = (s[p] > s[q]);
				break;
			}
		}

		if (!g)
		{
			bool carry = 1;
			int i = (n - 1) / 2;
			while (carry && i >= 0)
			{
				if (s[i] == '9')
					s[i] = '0';
				else
				{
					s[i] += 1;
					carry = 0;
				}
				i--;
			}
			if (carry)
			{
				n += 1;
				s[(n - 1) / 2] = '0';
				s[0] = '1';
			}
		}

		if (n % 2 == 0)
		{
			cout << s.substr(0, n / 2);
			reverse(s.begin(), s.begin() + n / 2);
			cout << s.substr(0, n / 2) << endl;
		}
		else
		{
			cout << s.substr(0, n / 2);
			reverse(s.begin(), s.begin() + n / 2 + 1);
			cout << s.substr(0, n / 2 + 1) << endl;
		}


	}

	return 0;
}