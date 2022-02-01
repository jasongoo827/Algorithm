#include <bits/stdc++.h>

using namespace std;

int test_num, ventil_t;
int nClass_20, nClass_30, nClass_60;
vector<pair<string, pair<int, int>>> class_20;
vector<pair<string, pair<int, int>>> class_30;
vector<pair<string, pair<int, int>>> class_60;
vector<pair<string, pair<int, int>>> class_on;

vector<vector<pair<string, pair<int, int>>>> tests;
vector<vector<vector<int>>> classes;

bool cmp(const pair<string, pair<int,int>> &a, const pair<string, pair<int, int>> &b)
{
	return a.second.first < b.second.first;
}

int operating(int start, int type)
{
	int i, nClass;

	if (type == 0) nClass = nClass_20;
	else if (type == 1) nClass = nClass_30;
	else if (type == 2) nClass = nClass_60;

	if (nClass > 0) {
		for (i = 0; i < nClass; i++) {
			if (classes[type][i].size() > 0 && tests[type][classes[type][i].back()].second.second + ventil_t <= start) {
				return i;
			}
		}
		nClass++;
		if (type == 0) nClass_20 = nClass;
		else if (type == 1) nClass_30 = nClass;
		else if (type == 2) nClass_60 = nClass;
		return i;
	}
	else {
		nClass++;
		if (type == 0) nClass_20 = nClass;
		else if (type == 1) nClass_30 = nClass;
		else if (type == 2) nClass_60 = nClass;
		return 0;
	}

}

void Scheduling(int nTest, int type)
{
	int i = 0;
	while (i < nTest) {
		int classNum = operating(tests[type][i].second.first, type);
		classes[type][classNum].push_back(i);
		i++;
	}
}

int main()
{
	string test_name;
	int start_t, end_t, cnt, total = 0;

	cout << "배정할 시험의 개수를 입력하시오: "; cin >> test_num;
	cout << "환기시간을 입력하시오: "; cin >> ventil_t;

	for(int i = 0; i < test_num; i++) {
		cout << i + 1 <<"번째 강의명을 입력하세요: "; cin >> test_name;
		cout << "시험 시작 시간을 입력하세요: "; cin >> start_t;
		cout << "시험 종료 시간을 입력하세요: "; cin >> end_t;
		cout << "시험 인원을 입력하세요: "; cin >> cnt;
		cout << endl;

		if (cnt <= 20) class_20.push_back(make_pair(test_name, make_pair(start_t, end_t)));
		else if (cnt <= 30) class_30.push_back(make_pair(test_name, make_pair(start_t, end_t)));
		else if (cnt <= 60) class_60.push_back(make_pair(test_name, make_pair(start_t, end_t)));
		else class_on.push_back(make_pair(test_name, make_pair(start_t, end_t)));
	}

	sort(class_20.begin(), class_20.end(), cmp);
	sort(class_30.begin(), class_30.end(), cmp);
	sort(class_60.begin(), class_60.end(), cmp);
	sort(class_on.begin(), class_on.end(), cmp);

	tests.push_back(class_20);
	tests.push_back(class_30);
	tests.push_back(class_60);

	for (int i = 0; i < 3; i++) {
		vector<vector<int>> v;
		classes.push_back(v);
		for (int j = 0; j < test_num; j++) {
			vector<int> element(0);
			classes[i].push_back(element);
		}
	}

	for (int i = 0; i < 3; i++) Scheduling(tests[i].size(), i);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < test_num; j++) {
			if (classes[i][j].size() == 0) break;
			total++;
			cout << "CLASS " << 10 * i + (j + 1) << ": ";
			for (int k = 0; k < classes[i][j].size(); k++) {
				cout << tests[i][classes[i][j][k]].first << "(" << tests[i][classes[i][j][k]].second.first << "-" << tests[i][classes[i][j][k]].second.second << ") ";
			}
			cout << endl;
		}
		cout << endl;
	}

	for (int i = 0; i < class_on.size(); i++) {
		cout << "온라인: " << class_on[i].first << "(" << class_on[i].second.first << "-" << class_on[i].second.second << ") ";
	}
	cout << endl;

	cout << "총 " << total << "개 강의실이 필요합니다." << endl;

	return 0;
}