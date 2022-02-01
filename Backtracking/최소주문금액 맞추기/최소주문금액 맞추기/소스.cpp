#include <bits/stdc++.h>

using namespace std;

int min_order, comb_num = 0;
bool flag = false;
typedef pair<string, int> items;
vector<items> comb;
vector<vector<items>> ans;
bool visited[28] = { false, };
items item_list[] = {
	{"더블화이트갈릭팩", 22100},
	{"화이트갈릭팩", 20600},
	{"바삭킹 & 모짜볼10, 까망베르치즈소스", 16000},
	{"몬스터X세트", 11700},
	{"통새우X세트", 11100},
	{"더블화이트갈릭와퍼세트", 12200},
	{"스태커2와퍼세트", 10200},
	{"기네스콰트로치즈와퍼세트", 10700},
	{"콰트로치즈와퍼세트", 10100},
	{"베이컨치즈와퍼세트", 10100},
	{"리얼와퍼세트", 9300},
	{"불고기와퍼세트", 9300},
	{"치즈와퍼세트", 9900},
	{"더블화이트갈릭와퍼", 9900},
	{"화이트갈릭와퍼", 7900},
	{"스태커2와퍼", 9600},
	{"리얼와퍼", 7600},
	{"치즈와퍼", 7000},
	{"통새우와퍼주니어", 5800},
	{"와퍼주니어", 5200},
	{"치즈와퍼주니어", 5500},
	{"앵그리너겟킹4조각", 3100},
	{"치즈 프라이", 3300},
	{"프렌치프라이(L)", 3300},
	{"프렌치프라이(R)", 2400},
	{"아이스아메리카노", 2200},
	{"코카콜라(L)", 2700},
	{"코카콜라(R)", 2500}
};

//금액이 더 작은데 끝까지 탐색했을 경우
//금액 딱 맞출 경우

void make_comb(int total)
{
	if (total == min_order) {
		if (comb_num != 0 && ans[0][0].second > comb[0].second) return;
		for (int j = 0; j < (int)comb.size(); j++) {
			ans[comb_num].push_back(make_pair(comb[j].first, comb[j].second));
		}
		comb_num++;
		flag = true;
		return;
	}
	if (total > min_order) {
		return;
	}

	int i = 0;
	for (auto& item : item_list) {
		if (!visited[i]) {
			comb.push_back(make_pair(item.first, item.second));
			visited[i] = true;
			make_comb(total + item.second);
			comb.pop_back();
			visited[i] = false;
		}
		i++;
	}

	if (!flag && total < min_order) {
		return;
	}
}


int main()
{
	cout << "최소 주문 금액 >> "; cin >> min_order;

	for (int i = 0; i < 28; i++) {
		vector<items> v(0);
		ans.push_back(v);
	}

	while (1) {
		make_comb(0);
		if (ans.size() > 0) {
			for (int i = 0; i < ans.size(); i++) {
				if (ans[i].size() == 0) continue;
				for (int j = 0; j < ans[i].size(); j++) {
					cout << ans[i][j].first << " " << ans[i][j].second << " ";
				}
				cout << endl;
			}
			break;
		}
		min_order += 100;
	}

	return 0;
}