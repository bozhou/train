#include <iostream>
// count the height and # nodes
// when inserting [1..n] (in this order)
// into a B-tree of min-degree 3

using namespace std;

int pow(int a, int b) // calculate a^b
{
	int ans = 1;
	while (b)
	{
		if (b & 1) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}


int f(int h)  // [1 + 3 + 3^2 + ... + 3^(h-1)]
{
	/*
	int n = 1;
	int k = 3;
	while (--h)
	{
		n += k;
		k *= 3;
	}
	return n;
	*/
	return (pow(3, h) - 1) / 2;
}


int main()
{
	int n;
	cout << "Input n: ";
	cin >> n;

	int h = 0;
	int min_n = 1;

	while (min_n <= n)
	{
		h++;
		min_n = 1 + 2 * f(h) * 2;
	}
	h--;
	cout << "Height is: " << h << endl;

	if (n <= 4)
	{
		cout << "# nodes is: " << 1 << endl;
		return 0;
	}

	int nodes = 1 + 2 * f(h);
	min_n = 1 + 2 * f(h) * 2;

	while (h > 0)
	{
		while (n >= min_n + 1 + f(h) * 2)
		{
			nodes += f(h);
			min_n += 1 + f(h) * 2;
		}
		h--;
	}
	cout << "# nodes is: " << nodes << endl;

	return 0;
}