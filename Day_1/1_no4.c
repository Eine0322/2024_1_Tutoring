// No.4 포인터 기초
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 10;
	int* p = &a;

	printf("포인터주소: %d\n포인터주소의 값: %d\n정수형 변수의 값: %d\n정수형 변수의 주소: %d", p, *p, a, &a);
}