#include <bits/stdc++.h>

using namespace std;

int get_len(int n)
{
	int len = 0;
	while (n > 0) {
		n /= 10;
		len++;
	}
	return len;
}

int karatsuba(int a, int b, int len)
{
	if (len < 2) return a * b;

	int L, M, N, x1, y1, x0, y0;
	int half = len / 2;
	int po = pow(10, half);

	x1 = a / po, y1 = b / po;
	x0 = a % po, y0 = b % po;

	L = karatsuba(x1, y1, half);
	N = karatsuba(x0, y0, half);
	M = L + N - karatsuba(x1 - x0, y1 - y0, min(get_len(x1 - x0), get_len(y1 - y0)));

	return L * po * po + M * po + N;
}


int main()
{
	int a = 2462, b = 8014;
	cout << "a * b = ";
	cout << karatsuba(a, b, 4);
	cout << " ÀÔ´Ï´Ù." << endl;
	return 0;
}