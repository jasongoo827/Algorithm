#include <bits/stdc++.h>

using namespace std;

int min_order, comb_num = 0;
bool flag = false;
typedef pair<string, int> items;
vector<items> comb;
vector<vector<items>> ans;
bool visited[28] = { false, };
items item_list[] = {
	{"����ȭ��Ʈ������", 22100},
	{"ȭ��Ʈ������", 20600},
	{"�ٻ�ŷ & ��¥��10, �������ġ��ҽ�", 16000},
	{"����X��Ʈ", 11700},
	{"�����X��Ʈ", 11100},
	{"����ȭ��Ʈ�������ۼ�Ʈ", 12200},
	{"����Ŀ2���ۼ�Ʈ", 10200},
	{"��׽���Ʈ��ġ����ۼ�Ʈ", 10700},
	{"��Ʈ��ġ����ۼ�Ʈ", 10100},
	{"������ġ����ۼ�Ʈ", 10100},
	{"������ۼ�Ʈ", 9300},
	{"�Ұ����ۼ�Ʈ", 9300},
	{"ġ����ۼ�Ʈ", 9900},
	{"����ȭ��Ʈ��������", 9900},
	{"ȭ��Ʈ��������", 7900},
	{"����Ŀ2����", 9600},
	{"�������", 7600},
	{"ġ�����", 7000},
	{"���������ִϾ�", 5800},
	{"�����ִϾ�", 5200},
	{"ġ������ִϾ�", 5500},
	{"�ޱ׸��ʰ�ŷ4����", 3100},
	{"ġ�� ������", 3300},
	{"����ġ������(L)", 3300},
	{"����ġ������(R)", 2400},
	{"���̽��Ƹ޸�ī��", 2200},
	{"��ī�ݶ�(L)", 2700},
	{"��ī�ݶ�(R)", 2500}
};

//�ݾ��� �� ������ ������ Ž������ ���
//�ݾ� �� ���� ���

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
	cout << "�ּ� �ֹ� �ݾ� >> "; cin >> min_order;

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