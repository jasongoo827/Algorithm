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
	cout << "�� ���� �Է��Ͻÿ�: ";
	cin >> n >> m;
	int big = max(n, m);
	int small = min(n, m);

	cout << "�� ���� �ִ�����: " << gcd(big, small) << endl;

	return 0;
}