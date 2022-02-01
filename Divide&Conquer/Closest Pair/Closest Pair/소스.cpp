#include <bits/stdc++.h>

using namespace std;

#define MAX 30
#define power(a) (a)*(a)

struct point
{
	int xPos;
	int yPos;
};

point points[MAX];
point min_p1, min_p2;
int ret = std::numeric_limits<int>::max();

void createRandom()
{
	for (int i = 0; i < MAX; i++) {
		points[i].xPos = rand() % MAX;
		points[i].yPos = rand() % MAX;
		for (int j = 0; j < MAX; j++) {
			if (points[i].xPos == points[j].xPos && i != j) i--;
		}
	}
	return;
}

bool cmp1(point p1, point p2)
{
	return p1.xPos < p2.xPos;
}

bool cmp2(point p1, point p2)
{
	return p1.yPos < p2.yPos;
}

int dist(point p1, point p2)
{
	return power(p1.xPos - p2.xPos) + power(p1.yPos - p2.yPos);
}

void closest_pair(int start, int end)
{
	if (start == end) return;
	if (end - start == 1) {
		if (dist(points[start], points[end]) < ret) {
			ret = dist(points[start], points[end]);
			min_p1 = points[start], min_p2 = points[end];
		}
		return;
	}
	int mid = (start + end) / 2;

	closest_pair(start, mid);
	closest_pair(mid + 1, end);

	point pos[MAX];
	int line = (points[mid].xPos + points[mid + 1].xPos) / 2;
	int len = 0;
	int index = 0;

	for (int i = start; i <= end; i++) {
		if (power(line - points[i].xPos) < ret) {
			index = i;
			pos[i].xPos = points[i].xPos;
			pos[i].yPos = points[i].yPos;
			len++;
		}
	}	

	if (len == 0) return;
	sort(pos + (index - len + 1), pos + index + 1, cmp2);

	for (int i = index - len + 1; i < index + 1; i++) {
		for (int j = i + 1; j < start + len; j++) {
			if (power(pos[i].yPos - pos[j].yPos) >= ret) break;
			if (dist(pos[i], pos[j]) < ret) {
				ret = dist(pos[i], pos[j]);
				min_p1 = pos[i];
				min_p2 = pos[j];
			}
		}
	}
	return;
}

int main()
{
	createRandom();
	sort(points, points + MAX, cmp1);// X좌표 오름차순으로 정렬

	for (int i = 0; i < MAX; i++) {
		printf("(%d, %d) ", points[i].xPos, points[i].yPos);
	}
	printf("\n");

	closest_pair(0, MAX - 1);

	printf("가장 최소의 거리: %lf\n", sqrt(ret));
	printf("가장 최소의 쌍: ");
	printf("(%d, %d) ", min_p1.xPos, min_p1.yPos);
	printf("(%d, %d)\n", min_p2.xPos, min_p2.yPos);

	return 0;
}