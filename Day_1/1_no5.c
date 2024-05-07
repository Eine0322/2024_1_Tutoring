// No.5 포인터 사용하여 정수 값 곱하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a;
	int* p = &a;
	printf("N: ");
	scanf("%d", p);
	printf("N*2: %d", *p * 2);
}