// No.6 포인터 사용하여 두 정수 값 교환하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int tmp,a,b;
	int* p = &a;
	int* q = &b;

	printf("전환 전 a b: ");
	scanf("%d %d", p, q);
	tmp = *p;
	*p = *q;
	*q=tmp;
	printf("전환 후 a b: %d %d", a, b);
}