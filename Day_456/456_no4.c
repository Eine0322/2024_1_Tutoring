// No.4 ��Ľ� ���ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
double result = 1;

void gauss(double** a, int n, int m, double* tmp) {
	// �ִ밢���� �Ʒ� �� ���ֱ�
	for (int i = 1; i < n - m; i++) {
		double div = a[m + i][m] / a[m][m];
		for (int j = 0; j < n; j++) {
			tmp[j] = div * a[m][j];
			a[m + i][j] -= tmp[j];
		}
	}
}

 int main() {
	 int n;
	 scanf("%d", &n);

	 // A �迭 �����Ҵ�
	 double** a = (double**)malloc(sizeof(double*) * n);
	 for (int i = 0; i < n; i++) {
		 a[i] = (double*)malloc(sizeof(double) * n);
	 }

	 // tmp �迭 �����Ҵ�
	 double* tmp = (double*)malloc(sizeof(double) * n);

	 srand(time(0)); //���� ���� -10~10
	 for (int i = 0; i < n; i++) {
		 for (int j = 0; j < n; j++) {
			 a[i][j] = rand() % 21-10;
			 printf("%4.0f ", a[i][j]);
		 }
		 printf("\n");
	 }

	 // �ִ밢 ���� 0 �ٲ��ֱ�
	 for (int i = 0; i < n - 1; i++) {
		 if (a[i][i] == 0) {
			 for (int j = 0; j < n;j++) {
				 tmp[j] = a[i][j];
				 a[i][j] = a[i + 1][j];
				 a[i + 1][j] = tmp[j];
			 }
			 result *= -1;
		 }
	 }

	 // ���콺 �ҰŹ�
	 for (int i = 0; i < n;i++) {
		 if (i<n-1)
			gauss(a, n, i, tmp);
		 result *= a[i][i];
	 }
	 
	 // ��� ���
	 printf("RESULT: %-.0f\n", result);

	 // A, tmp �迭 free
	 for (int i = 0; i < n; i++) {
		 free(a[i]);
	 }
	 free(a);
	 free(tmp);
 }
