//No.6 아다마르 행렬 구현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
func(int** arr, int x, int y, int a, int d);

func(int** arr, int x, int y, int a, int d) {
	if (a == 1) {
		arr[x][y] = d;
		return 0;
	}
	else {
		func(arr, x, y, a / 2, d);
		func(arr, x, y + a / 2, a / 2, d);
		func(arr, x + a / 2, y, a / 2, d);
		func(arr, x + a / 2, y + a / 2, a / 2, -d);
	}
}

int main() {
	int n, N;
	N = 1;
	printf("Enter the value of n for Hadamard matrix (2^n x 2^n): ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		N = N * 2;
	}
	int** mat = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		mat[i] = (int*)malloc(sizeof(int) * N);
	}
	func(mat, 0, 0, N, 1);
	printf("\nHadamard Matrix of size %dx%d:\n", N, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%4d ", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}