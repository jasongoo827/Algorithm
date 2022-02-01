#include <bits/stdc++.h>
#define MAXN 10
using namespace std;

double sim_equ[MAXN][MAXN + 1];
int row, col;
vector<double> sol_list;

void Gaussian_elimination()
{
	for (int i = 0; i < col; i++) {
		for (int j = i + 1; j < col; j++) {
			if (sim_equ[j][i] == 0) continue;
			double mul = sim_equ[j][i] / sim_equ[i][i] * (-1);
			for (int k = 0; k < row + 1; k++) sim_equ[j][k] += sim_equ[i][k] * mul;
		}
	}

	int end = row - 1;
	for (int i = col - 1; i >= 0; i--) {
		double sum = 0;
		for (int j = row - 1; j >= end; j--) {
			sum += sim_equ[i][j] * sol_list[j];
		}
		sol_list[end] = (sim_equ[i][row] - sum) / sim_equ[i][end];
		end--;
	}
	return;
}

int main()
{
	cout << "���� �������� ������ �Է��ϼ���(�ִ� 10��): "; cin >> col;
	cout << "�� ���� �������� ���� ������ �Է��ϼ���(�ִ� 10��):"; cin >> row;

	cout << "�� ������������ ����� ����� �Է��ϼ���" << endl;
	for (int i = 0; i < col; i++) {
		cout << (i + 1) << "��° ��: ";
		for (int j = 0; j < row + 1; j++) {
			cin >> sim_equ[i][j];
		}
	}
	for (int i = 0; i < row; i++) sol_list.push_back(0);

	Gaussian_elimination();

	cout << "���� �������� ��" << endl;
	for (int i = 0; i < row; i++) cout << i + 1 << "��° ��: " << sol_list[i] << endl;

	return 0;
}