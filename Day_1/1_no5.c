// No.5 ������ ����Ͽ� ���� �� ���ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a;
	int* p = &a;
	printf("N: ");
	scanf("%d", p);
	printf("N*2: %d", *p * 2);
}