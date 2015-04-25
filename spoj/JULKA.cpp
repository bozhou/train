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

// C++ big integer template
// author: yubowenok (Bowen Yu)
/*
The MIT License (MIT)

Copyright (c) 2015 Bowen Yu

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#define BIGINT_SIZE 100	// support STEP*SIZE integer
#define BIGINT_STEP 9	// elementary step 10^k
#define BIGINT_CHARSIZE (BIGINT_SIZE*BIGINT_STEP+1)
class bigint{
public:
	bool negative;
	int lenChars, lenNumbers;
	ll divider, numbers[BIGINT_SIZE];
	char chars[BIGINT_CHARSIZE];
	static const int step = BIGINT_STEP;
	// constructors & initializer
	void inline init(){ negative = 0; lenChars = lenNumbers = 0; chars[0] = 0; divider = (ll)pow(10.0, (double)step); }
	bigint(){ init(); }
	bigint(const bigint &num){ init(); copyFromBigint(num); }
	bigint(int num){ init(); convertLonglongToNumbers((ll)num); }
	bigint(ll num){ init(); convertLonglongToNumbers(num); }
	// rev determines if the input is in reversed character order, one hundred in reversed order is "100"
	bigint(char *str, bool rev){ init(); int len = strlen(str); if (str[0] == '-'){ negative = 1; len--; } if (rev) REP(i, 0, len) chars[i] = str[len - 1 - i + negative]; else REP(i, 0, len) chars[i] = str[i + negative]; chars[len] = 0; lenChars = len; convertCharsToNumbers(); }
	// conversion functions
	void convertCharsToNumbers(){ for (int i = 0; i<lenChars; i += step){ ll base = 1, sum = 0; for (int j = 0; i + j<lenChars && j<step; j++){ ll x = (ll)(chars[i + j] - '0'); sum += x*base; base *= 10; } numbers[i / step] = sum; lenNumbers = i / step + 1; } }
	void convertNumbersToChars(){ int len = 0; REP(i, 0, lenNumbers){ int x = (int)numbers[i], j = 0; while (x){ chars[len++] = '0' + x % 10; x /= 10; j++; } while (j<step){ chars[len++] = '0'; j++; } } lenChars = len; removeLeadingCharZeros(); }
	void convertLonglongToNumbers(ll num){ int len = 0; ll lnum = (ll)num; if (lnum<0){ negative = 1; lnum = -lnum; } while (lnum){ numbers[len++] = lnum%divider; lnum /= divider; } if (!len) numbers[len++] = 0; lenNumbers = len; }
	void removeLeadingNumberZeros(){ int len = lenNumbers; for (int i = lenNumbers - 1; i >= 1; i--){ if (numbers[i] == 0) len = i; else break; } lenNumbers = len; }
	void removeLeadingCharZeros(){ int len = lenChars; for (int i = lenChars - 1; i >= 1; i--){ if (chars[i] == '0'){ chars[i] = 0; len = i; } else break; } lenChars = len; }
	// arithmetic
	bigint operator + (const bigint &another) const{
		// negative handling
		if (negative && !another.negative){
			bigint a = abs();
			if (a <= another) return another - a;
			else return (a - another).negate();
		}
		else if (!negative && another.negative){
			bigint b = another.abs();
			if (*this >= b) return *this - b;
			else return (b - *this).negate();
		}
		bigint ans(0);
		ans.negative = negative;
		int l1 = lenNumbers, l2 = another.lenNumbers, len = l1>l2 ? l1 : l2;
		ll carry = 0;
		REP(i, 0, len){
			ans.numbers[i] = carry;
			if (i<l1) ans.numbers[i] += numbers[i];
			if (i<l2) ans.numbers[i] += another.numbers[i];
			carry = 0;
			if (ans.numbers[i] >= divider){ ans.numbers[i] %= divider; carry = 1; }
		}
		if (carry) ans.numbers[len++] = carry;
		ans.lenNumbers = len;
		REP(i, 0, len) if (ans.numbers[i]<0) cerr << "Cannot-be in Plus";
		return ans;
	}
	bigint operator - (const bigint &another) const{
		// handling negative
		if (negative && !another.negative) return (abs() + another).negate();
		else if (!negative && another.negative) return *this + another.abs();
		else if (negative && another.negative) return *this + another.negate();//XXX
		ll dir = *this >= another ? 1 : -1;
		bigint ans(0);
		int l1 = lenNumbers, l2 = another.lenNumbers, len = l1>l2 ? l1 : l2;
		ll carry = 0;
		REP(i, 0, len){
			ans.numbers[i] = -carry;
			if (i<l1) ans.numbers[i] += numbers[i] * dir;
			if (i<l2) ans.numbers[i] += -another.numbers[i] * dir;
			carry = 0;
			if (ans.numbers[i]<0){ ans.numbers[i] += divider; carry = 1; }
		}
		if (carry) cerr << "Cannot-be in minus" << endl;
		ans.lenNumbers = len;
		ans.removeLeadingNumberZeros();
		ans.negative = dir>0 ? 0 : 1;
		return ans;
	}
	bigint operator * (const bigint &another) const{
		bigint ans(0);
		if (negative && !another.negative || !negative && another.negative) ans.negative = 1;
		if (*this == 0 || another == 0) return bigint(0);
		int l1 = lenNumbers, l2 = another.lenNumbers;
		ll carry;
		REP(i, 0, l1 + l2) ans.numbers[i] = 0;
		REP(i, 0, l1){
			carry = 0;
			REP(j, 0, l2){
				ans.numbers[i + j] += numbers[i] * another.numbers[j] + carry;
				carry = ans.numbers[i + j] / divider;
				ans.numbers[i + j] %= divider;
			}
			if (carry) ans.numbers[i + l2] += carry;	// cannot carry over
		}
		ans.lenNumbers = l1 + l2;
		ans.removeLeadingNumberZeros();
		return ans;
	}
	bigint operator / (const bigint &another) const{
		bigint ans(0);
		if (negative && !another.negative || !negative && another.negative) ans.negative = 1;
		if (*this == 0) return bigint(0);
		if (abs()<another.abs()) return bigint(0);
		int l1 = lenNumbers, l2 = another.lenNumbers, l3, len = l1 - l2 + 1;
		ll dividend[BIGINT_SIZE];
		REP(i, 0, l1) dividend[i] = numbers[i];
		ll tmp[BIGINT_SIZE], carry;
		for (int i = len - 1; i >= 0; i--){
			ll l = 0, r = divider - 1;
			while (l <= r){
				ll m = (l + r) / 2; carry = 0;
				REP(j, 0, l2){
					tmp[j] = carry + another.numbers[j] * m;
					carry = 0;
					if (tmp[j] >= divider){ carry = tmp[j] / divider; tmp[j] %= divider; }
				}
				l3 = l2;
				if (carry) tmp[l3++] = carry;
				bool tooLarge = 0;
				if (i + l3>l1) tooLarge = 1;
				else if (i + l3<l1 && dividend[i + l3]){ // dividend has larger length
				}
				else{
					for (int j = l3 - 1; j >= 0; j--){
						if (tmp[j]>dividend[i + j]){ tooLarge = 1; break; }
						else if (tmp[j]<dividend[i + j]) break;
					}
				}
				// if no break, then equal is acceptable as not too large
				if (tooLarge) r = m - 1;
				else l = m + 1;
			}
			carry = 0;
			REP(j, 0, l2){
				tmp[j] = carry + another.numbers[j] * r;
				carry = 0;
				if (tmp[j] >= divider){ carry = tmp[j] / divider; tmp[j] %= divider; }
			}
			l3 = l2;
			if (carry) tmp[l3++] = carry;
			carry = 0;
			REP(j, 0, l3){
				dividend[i + j] -= carry + tmp[j];
				carry = 0;
				if (dividend[i + j]<0){ dividend[i + j] += divider; carry = 1; }
			}
			if (carry) dividend[i + l3] = 0;
			ans.numbers[i] = r;
		}
		ans.lenNumbers = len;
		ans.removeLeadingNumberZeros();
		return ans;
	}
	bigint operator % (const bigint &another) const{ bigint quotient = *this / another * another; return *this - quotient; }
	bigint & operator = (const bigint &another){ copyFromBigint(another); return *this; }
	bigint & operator += (const bigint &another){ return *this = *this + another; }
	bigint & operator -= (const bigint &another){ return *this = *this - another; }
	bigint & operator *= (const bigint &another){ return *this = *this * another; }
	bigint & operator /= (const bigint &another){ return *this = *this / another; }
	bigint & operator %= (const bigint &another){ return *this = *this % another; }
	// comparison
	bool smallerOrEqualThan(const bigint &another, bool canEqual) const{
		if (negative && !another.negative) return true;
		if (!negative && another.negative) return false;
		if (negative && another.negative) return abs() >= another.abs();
		if (lenNumbers>another.lenNumbers) return false;
		if (lenNumbers<another.lenNumbers) return true;
		for (int i = lenNumbers - 1; i >= 0; i--){
			if (numbers[i] > another.numbers[i]) return false;
			else if (numbers[i] < another.numbers[i]) return true;
		}
		return canEqual;
	}
	bool largerOrEqualThan(const bigint &another, bool canEqual) const{
		if (negative && !another.negative) return false;
		if (!negative && another.negative) return true;
		if (negative && another.negative) return abs() <= another.abs();
		if (lenNumbers>another.lenNumbers) return true;
		if (lenNumbers<another.lenNumbers) return false;
		for (int i = lenNumbers - 1; i >= 0; i--){ if (numbers[i] > another.numbers[i]) return true; else if (numbers[i] < another.numbers[i]) return false; }
		return canEqual;
	}
	bool operator < (const bigint &another) const{ return smallerOrEqualThan(another, false); }
	bool operator <= (const bigint &another) const{ return smallerOrEqualThan(another, true); }
	bool operator > (const bigint &another) const{ return largerOrEqualThan(another, false); }
	bool operator >= (const bigint &another) const{ return largerOrEqualThan(another, true); }
	bool operator != (const bigint &another) const{ return !(*this == another); }
	bool operator && (const bigint &another) const{ return (*this != 0) && (another != 0); }
	bool operator || (const bigint &another) const{ return (*this != 0) || (another != 0); }
	bool operator == (const bigint &another) const{ if (lenNumbers != another.lenNumbers || negative != another.negative) return false; REP(i, 0, lenNumbers) if (numbers[i] != another.numbers[i]) return false; return true; }
	// copy of ll operators
	bigint operator + (const ll &num) const{ return *this + bigint(num); }
	bigint operator - (const ll &num) const{ return *this - bigint(num); }
	bigint operator * (const ll &num) const{ return *this * bigint(num); }
	bigint operator / (const ll &num) const{ return *this / bigint(num); }
	bigint operator % (const ll &num) const{ return *this % bigint(num); }
	bool operator < (const ll &num) const{ return *this < bigint(num); }
	bool operator <= (const ll &num) const{ return *this <= bigint(num); }
	bool operator > (const ll &num) const{ return *this > bigint(num); }
	bool operator >= (const ll &num) const{ return *this >= bigint(num); }
	bool operator != (const ll &num) const{ return !(*this == num); }
	bool operator && (const ll &num) const{ return (*this != 0) && (num != 0); }
	bool operator == (const ll &num) const{ return *this == bigint(num); }
	bool operator || (const ll &num) const{ return (*this != 0) || (num != 0); }
	// function
	void copyFromBigint(const bigint &another){ negative = another.negative; lenNumbers = another.lenNumbers; REP(i, 0, lenNumbers) numbers[i] = another.numbers[i]; }
	bigint abs() const{ bigint ans(*this); ans.negative = 0; return ans; }
	bigint negate() const{ bigint ans(*this); ans.negative = !ans.negative; return ans; }
	friend bigint operator +(const bigint &num){ return bigint(num); }
	friend bigint operator -(const bigint &num){ return num.negate(); }
	friend bool operator !(const bigint &num){ return num == 0 ? true : false; }
	// input and output
	void print(){ convertNumbersToChars(); if (negative) printf("-"); for (int i = lenChars - 1; i >= 0; i--) printf("%c", chars[i]); }
	void print(ostream & os){ convertNumbersToChars(); if (negative) os << "-"; for (int i = lenChars - 1; i >= 0; i--) os << chars[i]; }
	friend inline ostream & operator << (ostream & os, const bigint &num){ bigint out(num); out.print(os); return os; }
	friend inline istream & operator >> (istream & is, bigint &num){ string str; is >> str; num = bigint((char *)str.c_str(), 1); return is; }
};



int main()
{
	char x[150], y[150];
	while (cin>>x>>y)
	{
		bigint a(x, 1);
		bigint b(y, 1);

		bigint c,d;
		c = a + b;
		d = a - b;
		c /= 2;
		d /= 2;
		cout << c << endl;
		cout << d << endl;
	}

	return 0;
}

