#include <bits/stdc++.h>

using namespace std;

#define N 10
bool checked[N];
int ret = std::numeric_limits<int>::max();

int cost[10][10] = {
	{13,6,7,12,14,15,10,11,15,4},
	{8,14,11,9,6,14,7,9,16,12},
	{10,8,10,10,8,15,11,5,7,9},
	{13,13,16,9,13,16,15,9,14,16},
	{11,4,9,14,12,11,5,16,8,14},
	{7,10,12,13,4,11,16,12,15,9},
	{6,11,10,11,13,15,7,16,11,12},
	{7,15,5,10,4,16,12,4,10,16},
	{5,14,10,15,8,8,8,14,14,4},
	{8,11,4,16,8,12,4,14,9,6}
};

void job_assignment(int person, int cost_sum)
{
	if (person == N) {
		ret = min(ret, cost_sum);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!checked[i]) {
			checked[i] = 1;
			job_assignment(person + 1, cost_sum + cost[person][i]);
			checked[i] = 0;
		}
	}

	return;
}

int main()
{
	clock_t start_t, end_t;

	start_t = clock();
	job_assignment(0, 0);
	end_t = clock();

	printf("프로그램 실행 시간: %lf\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
	printf("가장 최소의 비용: %d", ret);
	return 0;
}