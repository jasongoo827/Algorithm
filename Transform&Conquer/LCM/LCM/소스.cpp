#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	cout << "LCM(1071, 1029) = " << lcm(1071, 1029) << endl;

	return 0;
}