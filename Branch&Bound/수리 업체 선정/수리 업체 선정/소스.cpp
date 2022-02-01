#include <bits/stdc++.h>

using namespace std;
#define N 6
#define INT_MAX 100000

vector<string> item = { "������", "�ǿܱ�", "�����", "���Ϸ�", "����", "����" };
vector<int> com_kind;


struct Node {
	Node* parent;
	int pathCost;
	int cost;
	int comID;
	int itemID;
	bool assigned[N];
};

Node* newNode(int x, int y, bool assigned[], Node* parent)
{
	Node* node = new Node;

	for (int i = 0; i < N; i++) {
		node->assigned[i] = assigned[i];
	}
	node->assigned[y] = true;

	node->parent = parent;
	node->comID = x;
	node->itemID = y;

	return node;
}

int calculateCost(int costMatrix[N][N], int x, int y, bool assigned[])
{
	int cost = 0;

	bool available[N] = { true, true, true, true, true, true };

	for (int i = x + 1; i < N; i++) {
		int min = INT_MAX, minIndex = -1;
		for (int j = 0; j < N; j++) {
			if (costMatrix[i][j] == 0) continue;
			if (!assigned[j] && available[j] && costMatrix[i][j] < min) {
				minIndex = j;
				min = costMatrix[i][j];
			}
		}
		if (minIndex == -1) continue;
		cost += min;
		available[minIndex] = false;
	}

	return cost;
}

struct comp
{
	bool operator()(const Node* a, const Node* b) const
	{
		return a->cost > b->cost;
	}
};

void printComb(Node* min)
{
	if (min->parent == NULL) return;

	printComb(min->parent);
	cout << item[min->itemID] << "-" << "��ü" << char(min->comID + 'A') << " ";
}

int findMinCost(int costMatrix[N][N], int maxIndex)
{
	priority_queue<Node*, std::vector<Node*>, comp> pq;

	bool assigned[N] = { false };
	Node* root = newNode(-1, -1, assigned, NULL);
	root->pathCost = root->cost = 0;
	root->comID = -1;

	pq.push(root);

	while (!pq.empty()) {
		Node* min = pq.top();

		int i = min->comID + 1;

		if (i == N) {
			cout << "��ü ��õ ����: ";
			printComb(min);
			cout << endl;
			return min->cost;
		}

		if (i == maxIndex + 1) {
			cout << "��ü ��õ ����: ";
			printComb(min);
			cout << endl;
			return min->cost;
		}

		for (int k = 0; k < com_kind.size(); k++) {
			if (com_kind[k] == min->comID) {
				i = com_kind[k + 1];
				break;
			}
		}
		pq.pop();

		for (int j = 0; j < N; j++) {
			if (costMatrix[i][j] == 0) continue;
			if (!min->assigned[j]) {
				Node* child = newNode(i, j, min->assigned, min);
				child->pathCost = min->pathCost + costMatrix[i][j];
				child->cost = child->pathCost + calculateCost(costMatrix, i, j, child->assigned);
				pq.push(child);
			}
		}
	}
}

int main()
{
	//������ �ǿܱ� ����� ���Ϸ� ���� ����
	int totalMatrix[6][6] =
	{
		{20, 12, 18, 12, 230, 37},
		{23, 14, 29, 14, 150, 43},
		{17, 16, 15, 12, 300, 40},
		{19, 13, 23, 22, 220, 35},
		{21, 15, 15, 14, 190, 30},
		{25, 14, 16, 13, 280, 31}
	};

	string cmd;
	int cnt = 0, ret;
	bool item[N] = { false };

	while (1) {
		cout << "������ ��ǰ���� �Է��ϼ���: "; cin >> cmd;
		if (cmd == "Q") break;

		if (cmd == "������") {
			if (item[0]) cout << "�ش� ��ǰ�� �̹� �Է��ϼ̽��ϴ�.\n";
			else {
				item[0] = true;
				cnt++;
			}
		}
		else if (cmd == "�ǿܱ�") {
			if (item[1]) cout << "�ش� ��ǰ�� �̹� �Է��ϼ̽��ϴ�.\n";
			else {
				item[1] = true;
				cnt++;
			}
		}
		else if (cmd == "�����") {
			if (item[2]) cout << "�ش� ��ǰ�� �̹� �Է��ϼ̽��ϴ�.\n";
			else {
				item[2] = true;
				cnt++;
			}
		}
		else if (cmd == "���Ϸ�") {
			if (item[3]) cout << "�ش� ��ǰ�� �̹� �Է��ϼ̽��ϴ�.\n";
			else {
				item[3] = true;
				cnt++;
			}
		}
		else if (cmd == "����") {
			if (item[4]) cout << "�ش� ��ǰ�� �̹� �Է��ϼ̽��ϴ�.\n";
			else {
				item[4] = true;
				cnt++;
			}
		}
		else if (cmd == "����") {
			if (item[5]) cout << "�ش� ��ǰ�� �̹� �Է��ϼ̽��ϴ�.\n";
			else {
				item[5] = true;
				cnt++;
			}
		}
		else {
			cout << "������, �ǿܱ�, �����, ���Ϸ�, ����, ���� �����մϴ�.\n";
		}
	}

	bool com[N] = { false };
	char ch;

	for (int i = 0; i < cnt; i++) {
		cout << "���ϴ� ��ü �ĺ�" << i + 1 << "��?"; cin >> ch;
		com[ch - 'A'] = true;
	}

	int maxIndex = -1;
	for (int i = 0; i < N; i++) {
		if (com[i]) {
			maxIndex = max(maxIndex, i);
			com_kind.push_back(i);
		}
	}
	
	int costMatrix[N][N] = { 0, };

	for (int i = 0; i < N; i++) {
		if (com[i]) {
			for (int j = 0; j < N; j++) {
				if (item[j]) costMatrix[i][j] = totalMatrix[i][j];
			}
		}
	}

	ret = findMinCost(costMatrix, maxIndex);
	cout << "������: " << ret << endl;

	return 0;
}

