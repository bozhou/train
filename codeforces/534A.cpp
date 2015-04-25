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
#include <unordered_map>


using namespace std;
typedef long long ll;
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define EPS 1E-9
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))


int a[5005];

int main()
{

	int n;
	cin >> n;
	if (n <= 2)
		printf("1\n1");
	else if (n==3)
		printf("2\n1 3");
	else
	{
		int k = 1;
		for (int i = 1; i < n; i+=2) a[i] = k++;
		for (int i = 0; i < n; i += 2) a[i] = k++;
		printf("%d\n",n);
		for (int i = 0; i < n; i++) cout << a[i]<<" ";
	}


	return 0;
}