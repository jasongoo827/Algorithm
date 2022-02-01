#include <bits/stdc++.h>

using namespace std;

int task_num, nProcessor;
vector<pair<int, int>> task;
vector<vector<int>> processor;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first < b.first;
}

int operating(int start)
{
	int i;

	if (nProcessor > 0) {
		for (i = 0; i < nProcessor; i++) {
			if (processor[i].size() > 0 && task[processor[i].back()].second  <= start) {
				return i;
			}
		}
		nProcessor++;
		return i;
	}
	else {
		nProcessor++;
		return 0;
	}

}

void Scheduling(int nTask)
{
	int i = 0;
	while (i < nTask) {
		int processorNum = operating(task[i].first);
		processor[processorNum].push_back(i);
		i++;
	}
}

int main()
{
	int start_t, end_t, cnt, total = 0;

	cout << "작업의 개수를 입력하시오: "; cin >> task_num;

	for (int i = 0; i < task_num; i++) {
		cout << i + 1 << "번째 작업" << endl;
		cout << "시작 시간과 종료시간을 입력하세요: ";
		cin >> start_t >> end_t;
		cout << endl;

		task.push_back(make_pair(start_t, end_t));
	}

	sort(task.begin(), task.end(), cmp);

	for (int i = 0; i < task_num; i++) {
		vector<int> element(0);
		processor.push_back(element);
	}
	nProcessor = 0;

	Scheduling(task.size());

	for (int i = 0; i < task_num; i++) {
		if (processor[i].size() != 0) {
			cout << i + 1 << " processor: ";
			for (int j = 0; j < (int)processor[i].size(); j++) {
				cout << "(" << task[processor[i][j]].first << ", " << task[processor[i][j]].second << ") ";
			}
		}
		cout << endl;
	}
	return 0;
}