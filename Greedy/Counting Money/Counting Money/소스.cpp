#include <bits/stdc++.h>

using namespace std;

int kor_money[8] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };
int cnt[8] = { 0, };

void cal(int mon)
{
	for (int i = 0; i < 8; i++) {
		while (mon >= kor_money[i]) {
			cnt[i]++;
			mon -= kor_money[i];
		}
	}
}


int main()
{
	int money, paid;
	cin >> money >> paid;

	cal(paid-money);

	for (int i = 0; i < 8; i++) {
		cout << kor_money[i] << ": " << cnt[i] << endl;
	}

	return 0;
}