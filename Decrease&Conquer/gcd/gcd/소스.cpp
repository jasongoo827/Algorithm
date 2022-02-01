#include <bits/stdc++.h>

using namespace std;

int gcd(int n, int m)
{
	int tmp;
	while (m) {
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}


int main()
{
	int n, m;
	cout << "두 수를 입력하시오: ";
	cin >> n >> m;
	int big = max(n, m);
	int small = min(n, m);

	cout << "두 수의 최대공약수: " << gcd(big, small) << endl;

	return 0;
}