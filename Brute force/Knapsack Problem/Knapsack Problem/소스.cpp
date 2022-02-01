#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> item_list;
vector<int> chosen, checked;
int n, limit_weight;
int ret = std::numeric_limits<int>::min();

void checked_to_chosen()
{
	chosen.clear();
	for (int i = 0; i < (int)checked.size(); i++) {
		chosen.push_back(checked[i]);
	}
	return;
}


void knapsack(int item_cnt, int weight_sum, int value_sum) {
	if (item_cnt == n) {
		if (weight_sum <= limit_weight && ret < value_sum) {
			ret = value_sum;
			checked_to_chosen();
		}
		return;
	}
	if (weight_sum >= limit_weight) {
		if (weight_sum == limit_weight && ret < value_sum) {
			ret = value_sum;
			checked_to_chosen();
		}
		return;
	}

	checked.push_back(item_cnt + 1);
	knapsack(item_cnt + 1, weight_sum + item_list[item_cnt].first, value_sum + item_list[item_cnt].second);
	checked.pop_back();
	knapsack(item_cnt + 1, weight_sum, value_sum);

	return;
}


int main()
{
	int weight, value;
	clock_t start_t, end_t;

	cout << "item의 총 개수를 입력해주세요: ";
	cin >> n;
	cout << "총 무게의 limit을 정해주세요: ";
	cin >> limit_weight;


	for (int i = 0; i < n; i++) {
		cout << i + 1 << "번째 item의 weight: ";
		cin >> weight;
		cout << i + 1 << "번째 item의 value: ";
		cin >> value;
		item_list.push_back(make_pair(weight, value));
	}

	start_t = clock();
	knapsack(1, 0, 0);
	end_t = clock();

	cout << endl;
	cout << "가장 value가 큰 subset: " << endl;
	cout << "{";
	for (int i = 0; i < (int)chosen.size(); i++) {
		cout << chosen[i] << " ";
	}
	cout << "}";
	cout << endl;
	cout << "총 value 값: " << ret << endl;
	printf("프로그램 실행 시간 : % lf", (double)(end_t - start_t) / CLOCKS_PER_SEC);

	return 0;
}