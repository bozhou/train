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
#define INF 1E12
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

typedef pair<int, int> PII;


template<typename T> 
struct vec2{
	T x, y;
	vec2(){};
	vec2(T x_, T y_) { x = x_; y = y_; }

	vec2 operator-() const{ return vec2(-this->x, -this->y);}
	vec2 operator+(const vec2& u) const{ return vec2(this->x + u.x, this->y + u.y);}
	vec2 operator-(const vec2& u) const{ return vec2(this->x - u.x, this->y - u.y);}
	
	vec2& operator=(const vec2& u){ this->x = u.x; this->y = u.y; return *this; }
	vec2& operator+=(const vec2& u){ this->x += u.x; this->y += u.y; return *this; }
	vec2& operator-=(const vec2& u){ this->x -= u.x; this->y -= u.y; return *this; }
	
	bool operator==(const vec2& u) const { return (this->x == u.x && this->y == u.y); }
	bool operator<(const vec2& b) const // same as clockwise order, 12:00 is minimum
	{
		vec2 a = *this;
		bool aright = (a.x>0 || a.x == 0 && a.y > 0);
		bool bright = (b.x > 0 || b.x == 0 && b.y > 0);
		if (aright && !bright) return 1;
		if (!aright && bright) return 0;
		return (a.x*b.y < a.y*b.x);
	}

	double dist() { return sqrt((double)x*x + y*y); };
	static T cross(vec2 &a, vec2 &b){
		return a.x*b.y - a.y*b.x;
	}
	static T dot(vec2 &a, vec2 &b){
		return a.x*b.x + a.y*b.y;
	}
};


int main()
{
	int n;
	
	while (cin >> n, n > 0)
	{
		vector<vec2<double> > inp;
		vec2<double> vall(0, 0);
		for (int i = 0; i < n; i++)
		{
			double x, y;
			scanf("%lf%lf", &x, &y);
			inp.push_back(vec2<double>(x, y));
			vall += inp.back();
		}
		sort(inp.begin(), inp.end());
		
		double ans = 0;
		for (int s = 0; s < n; s++)
		{
			int t = (s+1)%n;
			while (vec2<double>::cross(inp[s], inp[t]) <= 0 && t != s)
			{
				t++; if (t == n) t = 0;
			}
			vec2<double>  v(0, 0);
			for (int i = s; i!=t ; i=(i+1)%n)v += inp[i];
			v += v;
			v -= vall;
			ans = max(ans,v.dist());
		}
		printf("Maximum distance = %.3f meters.\n", ans);
	}

	return 0;
}