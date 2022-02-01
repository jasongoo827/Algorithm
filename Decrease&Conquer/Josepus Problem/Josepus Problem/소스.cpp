#include <bits/stdc++.h>

using namespace std;

int n, k, tmp;

void jp(int people, int level)
{
	queue<int> q;

	for (int i = 1; i <= n; i++) q.push(i);

	while (q.size() > 1) {
		for (int i = 0; i < level - 1; i++) {
			tmp = q.front();
			q.push(tmp);
			q.pop();
		}
		tmp = q.front();
		cout << "사망자: " << tmp << endl;
		q.pop();
	}
	cout << "생존자: " << q.front() << endl;
}

int main()
{
	cout << "인원수와 constant factor를 입력하시오: ";
	cin >> n >> k;

	jp(n, k);

	return 0;
}