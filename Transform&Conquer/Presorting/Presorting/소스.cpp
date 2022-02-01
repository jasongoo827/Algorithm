#include <bits/stdc++.h>
#define MAXN 10000
#define NUM 1000

using namespace std;

int nums[MAXN];
int cnt_nums[NUM] = { 0, };
vector<pair<int,int>> cnt_sorted;

void brute_force(int arr[])
{
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < NUM; j++) {
			if (arr[i] == j) {
				cnt_nums[j]++;
				break;
			}
		}
	}
}

void presorting(int arr[])
{	
	int cnt = 0;
	for (int i = 0; i < MAXN; i++) {
		if (arr[i] == arr[i + 1]) {
			cnt += 1;
		}
		else {
			cnt_sorted.push_back(make_pair(arr[i], cnt+1));
			cnt = 0;
		}
	}
}

int main()
{
	clock_t start_t1, end_t1, start_t2, end_t2;

	srand(time(NULL));

	for (int i = 0; i < MAXN; i++) {
		nums[i] = rand() % 1000;
	}

	start_t1 = clock();
	brute_force(nums);
	end_t1 = clock();
	printf("브루트 포스 실행시간: %lf\n", (double)(end_t1 - start_t1) / CLOCKS_PER_SEC);

	sort(nums, nums + MAXN);

	start_t2 = clock();
	presorting(nums);
	end_t2 = clock();
	printf("presorting 실행 시간: %lf\n", (double)(end_t2 - start_t2) / CLOCKS_PER_SEC);
	for (int i = 0; i < (int)cnt_sorted.size(); i++) {
		printf("(%d,%d) ", cnt_sorted[i].first, cnt_sorted[i].second);
	}

	return 0;
}