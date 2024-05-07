// No.1 최대, 최소, 평균 구하기
#include <stdio.h>

int main() {
	int arr[10] = { 10,23,15,26,17,37,45,44,3,11 };
	int max = 0;
	int min = 0;
	double average = 0;

	/* Write Your Code */
	int i;

	min = arr[0];
	average += arr[0];

	for (i = 1; i < 10; i++) {
		if (arr[i] > max)
			max = arr[i];
		else if (arr[i] < min)
			min = arr[i];
		average += arr[i];
	}
	average /= 10;

	printf("가장 큰 수 : %d\n", max);
	printf("가장 작은 수 : %d\n", min);
	printf("배열의 평균값 : %f\n", average);
}