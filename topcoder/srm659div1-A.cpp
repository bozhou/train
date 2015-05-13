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

using namespace std;

#define MAX_N 4005

int A[MAX_N+1];
int BIT[MAX_N+1];
int lowbit(int x)
{
	return x&(-x);
}

void build()
{
	for (int i = 1; i <= MAX_N; i++)
	{
		BIT[i] = A[i];
		for (int j = i - 1; j>i - lowbit(i); j -= lowbit(j))
			BIT[i] += BIT[j];
	}
}
void edit(int i, int delta)
{
	for (int j = i; j <= MAX_N; j += lowbit(j))
		BIT[j] += delta;
}

int sum(int k)
{
	int ans = 0;
	for (int i = k; i > 0; i -= lowbit(i))
		ans += BIT[i];
	return ans;
}

class ApplesAndOrangesEasy {
public:
	int maximumApples(int N, int K, vector <int> info) {
		memset(A, 0, sizeof(A));
		int ans=0;
		for (int i : info) {
			A[i] = 1;
			ans++;
		}
		
		build();
		for (int s = 1; s <= N; s++)
		{
			if (A[s] == 0)
			{
				bool ok = 1;
				for (int p = max(0, s - K); p < s; p++)
					ok &= (sum(p + K) - sum(p) < K / 2);
				if (ok)
				{
					A[s] = 1;
					edit(s, 1);
					ans++;
				}
			}
		}
		return ans;
	}
};