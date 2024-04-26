// No.3 M by N 행렬 A와 AT의 행렬곱
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include<time.h>

// 행렬 곱하기
int multiple(int row, int col, int** a1, int** a2, int count) {
	int sum=0;
	for (int i = 0; i < count; i++) {
		sum += a1[row][i] * a2[i][col]; // 각 요소 곱한 값 더하기
	}
	return sum; // 값 반환
}

int main() {
	int m, n;
	printf("m by n 입력 (m n): ");
	scanf("%d %d", &m, &n);

	// AT 배열 동적할당
	int** a = (int**)malloc(sizeof(int*) * m); 
	for (int i = 0; i < m; i++) { 
		a[i] = (int*)malloc(sizeof(int) * n);
	}
	// AT 배열 동적할당
	int** at = (int**)malloc(sizeof(int*) * n); 
	for (int i = 0; i < n; i++) {
		at[i] = (int*)malloc(sizeof(int) * m);
	}
	// A*AT 배열 동적할당
	int** aat = (int**)malloc(sizeof(int*) * m);
	for (int i = 0; i < m; i++) {
		aat[i] = (int*)malloc(sizeof(int) * m);
	}
	// AT*A 배열 동적할당
	int** ata = (int**)malloc(sizeof(int*) * n); 
	for (int i = 0; i < n; i++) { 
		ata[i] = (int*)malloc(sizeof(int) * n);
	}

	// 배열 A 저장
	srand(time(0)); //난수 생성
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 201 - 100;
		}
	}
	// 배열 A transpose 저장
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			at[i][j] = a[j][i];
		}
	}

	// A 배열, AT 배열 출력
	printf("\nA 배열\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\nAT 배열 \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%3d ", at[i][j]);
		}
		printf("\n");
	}
	printf("---------------------------------------------------------------");

	// aat 계산
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			aat[i][j] = multiple(i, j, a, at, n);
		}
	}
	// aat 출력
	printf("\nA*AT 배열 \n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			printf("%6d ", aat[i][j]);
		}
		printf("\n");
	}

	// ata 계산
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ata[i][j] = multiple(i, j, at, a, m);
		}
	}
	// ata 출력
	printf("\nAT*A 배열 \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%6d ", ata[i][j]);
		}
		printf("\n");
	}


	for (int i = 0; i < m; i++) {
		free(a[i]);
	}
	free(a);
	for (int i = 0; i < n; i++) {
		free(at[i]);
	}
	free(at);
	for (int i = 0; i < m; i++) {
		free(aat[i]);
	}
	free(aat);
	for (int i = 0; i < n; i++) {
		free(ata[i]);
	}
	free(ata);
}