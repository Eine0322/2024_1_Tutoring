// No.4 행렬식 구하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
double result = 1;

void gauss(double** a, int n, int m, double* tmp) {
	// 주대각성분 아래 값 빼주기
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

	 // A 배열 동적할당
	 double** a = (double**)malloc(sizeof(double*) * n);
	 for (int i = 0; i < n; i++) {
		 a[i] = (double*)malloc(sizeof(double) * n);
	 }

	 // tmp 배열 동적할당
	 double* tmp = (double*)malloc(sizeof(double) * n);

	 srand(time(0)); //난수 생성 -10~10
	 for (int i = 0; i < n; i++) {
		 for (int j = 0; j < n; j++) {
			 a[i][j] = rand() % 21-10;
			 printf("%4.0f ", a[i][j]);
		 }
		 printf("\n");
	 }

	 // 주대각 성분 0 바꿔주기
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

	 // 가우스 소거법
	 for (int i = 0; i < n;i++) {
		 if (i<n-1)
			gauss(a, n, i, tmp);
		 result *= a[i][i];
	 }
	 
	 // 결과 출력
	 printf("RESULT: %-.0f\n", result);

	 // A, tmp 배열 free
	 for (int i = 0; i < n; i++) {
		 free(a[i]);
	 }
	 free(a);
	 free(tmp);
 }
