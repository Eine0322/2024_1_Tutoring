// No.3 M by N ��� A�� AT�� ��İ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include<time.h>

// ��� ���ϱ�
int multiple(int row, int col, int** a1, int** a2, int count) {
	int sum=0;
	for (int i = 0; i < count; i++) {
		sum += a1[row][i] * a2[i][col]; // �� ��� ���� �� ���ϱ�
	}
	return sum; // �� ��ȯ
}

int main() {
	int m, n;
	printf("m by n �Է� (m n): ");
	scanf("%d %d", &m, &n);

	// AT �迭 �����Ҵ�
	int** a = (int**)malloc(sizeof(int*) * m); 
	for (int i = 0; i < m; i++) { 
		a[i] = (int*)malloc(sizeof(int) * n);
	}
	// AT �迭 �����Ҵ�
	int** at = (int**)malloc(sizeof(int*) * n); 
	for (int i = 0; i < n; i++) {
		at[i] = (int*)malloc(sizeof(int) * m);
	}
	// A*AT �迭 �����Ҵ�
	int** aat = (int**)malloc(sizeof(int*) * m);
	for (int i = 0; i < m; i++) {
		aat[i] = (int*)malloc(sizeof(int) * m);
	}
	// AT*A �迭 �����Ҵ�
	int** ata = (int**)malloc(sizeof(int*) * n); 
	for (int i = 0; i < n; i++) { 
		ata[i] = (int*)malloc(sizeof(int) * n);
	}

	// �迭 A ����
	srand(time(0)); //���� ����
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 201 - 100;
		}
	}
	// �迭 A transpose ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			at[i][j] = a[j][i];
		}
	}

	// A �迭, AT �迭 ���
	printf("\nA �迭\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\nAT �迭 \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%3d ", at[i][j]);
		}
		printf("\n");
	}
	printf("---------------------------------------------------------------");

	// aat ���
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			aat[i][j] = multiple(i, j, a, at, n);
		}
	}
	// aat ���
	printf("\nA*AT �迭 \n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			printf("%6d ", aat[i][j]);
		}
		printf("\n");
	}

	// ata ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ata[i][j] = multiple(i, j, at, a, m);
		}
	}
	// ata ���
	printf("\nAT*A �迭 \n");
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