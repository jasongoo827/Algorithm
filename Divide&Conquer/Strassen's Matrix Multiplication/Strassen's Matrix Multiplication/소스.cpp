#include <bits/stdc++.h>

using namespace std;

void add(int len, int M1[2][2], int M2[2][2], int T[2][2])
{
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			T[i][j] = M1[i][j] + M2[i][j];
		}
	}
	return;
}

void sub(int len, int M1[2][2], int M2[2][2], int T[2][2])
{
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			T[i][j] = M1[i][j] - M2[i][j];
		}
	}
	return;
}


void strassen(int len, int A[2][2], int x1, int y1, int B[2][2], int x2, int y2, int C[2][2], int x3, int y3)
{
	if (len == 1) {
		C[x3][y3] = A[x1][y1] * B[x2][y2];
		return;
	}
	int T1[2][2] = {}, T2[2][2] = {};
	int M1[2][2] = {}, M2[2][2] = {}, M3[2][2] = {}, M4[2][2] = {}, M5[2][2] = {}, M6[2][2] = {}, M7[2][2] = {};

	add(len / 2, A, A, T1);
	add(len / 2, B, B, T2);
	strassen(len / 2, T1, 0, 0, T2, 0, 0, M1, 0, 0);

	add(len, A, A, T1);
	strassen(len/2, T1, )

}


int main()
{
	int A[2][2] = { {10,8},
					{12,11}};
	int B[2][2] = { {4,9},
					{8,13} };


}