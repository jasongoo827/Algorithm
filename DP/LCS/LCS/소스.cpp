#include <bits/stdc++.h>

#define LEN 6

using namespace std;

int cell[LEN + 1][LEN + 1] = { 0, };

int LCS(string code, string cmp)
{

	for (int i = 1; i <= LEN; i++) {
		for (int j = 1; j <= LEN; j++) {
			if (code[i] == cmp[j]) {
				cell[i][j] = cell[i - 1][j - 1] + 1;
			}
			else {
				cell[i][j] = max(cell[i][j - 1], cell[i - 1][j]);
			}
		}
	}

	return cell[LEN][LEN];
}

void init()
{
	for (int i = 0; i < LEN + 1; i++) {
		memset(cell[i], 0, sizeof(int) * (LEN + 1));
	}
	return;
}

int main()
{
	string input;

	cin >> input;

	string code1 = "tophat", code2 = "tomato";
	int tophat, tomato;

	tophat = LCS(input, code1);
	init();
	tomato= LCS(input, code2);

	if (tophat > tomato) cout << code1 << "으로 대체하세요!\n";
	else if (tophat < tomato) cout << code2 << "으로 대체하세요!\n";
	else cout << "둘 모두로 대체할 수 있습니다!\n";

	return 0;
}