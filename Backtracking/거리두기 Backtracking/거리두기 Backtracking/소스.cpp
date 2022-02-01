#include <bits/stdc++.h>

using namespace std;

int m, n, ret = 0;
int space[15][15];
bool blocked[15][16] = { false };
int visited[15];

void dfs(int cnt, int level, int ans)
{
	if (cnt == m * n) {
		ret = max(ret, ans);
		return;
	}

	int y = cnt / n, x = cnt % n;

	if (space[y][x] == 0) {
		if (!blocked[y][x]) {
			if (level == 1) {
				space[y][x] = 1;
				blocked[y][x] = true;
				blocked[y - 1][x] = blocked[y + 1][x] = true;
				blocked[y][x - 1] = blocked[y][x + 1] = true;
				dfs(cnt + 1, level, ans + 1);
			}
			else if (level == 2) {
				space[y][x] = 1;
				blocked[y][x] = true;
				blocked[y - 1][x] = blocked[y + 1][x] = true;
				blocked[y][x - 1] = blocked[y][x + 1] = true;
				blocked[y - 1][x - 1] = blocked[y - 1][x + 1] = true;
				blocked[y + 1][x - 1] = blocked[y + 1][x + 1] = true;
				dfs(cnt + 1, level, ans + 1);
			}
			else if (level == 3) {
				space[y][x] = 1;
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						blocked[i][x] = blocked[y][j] = true;
						if (i - y == abs(j - x)) blocked[i][j] = true;
					}
				}
				dfs(cnt + 1, level, ans + 1);
			}
		}
		else dfs(cnt + 1, level, ans);
	}
	else dfs(cnt + 1, level, ans);
}

int main()
{
	int level, y, x;

	cout << "공간 크기: "; cin >> m >> n;
	cout << "거리두기 단계: "; cin >> level;
	cout << "지정석 좌표: "; cin >> y >> x;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			space[i][j] = 0;
		}
	}
	space[y][x] = 1, blocked[y][x] = true;

	if (level == 1) {
		blocked[y - 1][x] = blocked[y + 1][x] = true;
		blocked[y][x - 1] = blocked[y][x + 1] = true;
	}
	else if (level == 2) {
		blocked[y - 1][x] = blocked[y + 1][x] = true;
		blocked[y][x - 1] = blocked[y][x + 1] = true;
		blocked[y - 1][x - 1] = blocked[y - 1][x + 1] = true;
		blocked[y + 1][x - 1] = blocked[y + 1][x + 1] = true;
	}
	else if (level == 3) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				blocked[i][x] = blocked[y][j] = true;
				if (abs(i - y)  == abs(j - x)) blocked[i][j] = true;
			}
		}
	}

	dfs(0, level, 1);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << space[i][j] << " ";
		}
		cout << endl;
	}

	cout << "이용할 수 있는 인원은 " << ret <<"명입니다." << endl;

	return 0;
}