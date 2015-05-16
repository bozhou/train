/*
ID: zapray.1
PROG: contact
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
//#include <unordered_set>

using namespace std;
typedef long long ll;
#define REP(i,s,t) for(int i=(s); i<(t); i++)
#define FILL(x,v) memset(x,v, sizeof(x))


string get(int x, int l)
{
	string ans;
	for(int i=0; i<l; i++)
	{
		ans.push_back('0'+bool(x&(1<<i)));
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

//#define LOCAL
int main() {
#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("contact.out", "w", stdout);
	freopen("contact.in", "r", stdin);
#endif // LOCAL	

	int a,b,n;
	cin>>a>>b>>n;
	string s;
	string tmp;
	while(cin>>tmp)
	{
		s+=tmp;
	}
	map<int, vector<string> > ans;
	int cnt=0;
	for(int l = a; l<=min(b,(int)s.size()); l++)
	{
		int x=0;
		for(int k=0; k<l-1; k++) x=(x<<1)+(s[k]=='1');
		map<int, int> m;
		for(int k=l-1; k<s.size(); k++)
		{
			x = (x<<1)%(1<<l) +(s[k]=='1');
			m[x]++;
		}
		for(auto it = m.begin(); it!=m.end(); it++)
		{
			int freq = it->second;
			int x= it->first;
			ans[freq].push_back(get(x,l));
		}
	}
	int i=0;
	for (auto it = ans.rbegin(); it != ans.rend() && i<n; i++, it++)
	{
		printf("%d\n", it->first);
		for(int j=0; j<it->second.size(); j++)
		{
			cout<<(it->second)[j]<<" \n"[ (j==it->second.size()-1)||(j%6==5) ];
		}
	}


	return 0;
}
