// No.4 ������ ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 10;
	int* p = &a;

	printf("�������ּ�: %d\n�������ּ��� ��: %d\n������ ������ ��: %d\n������ ������ �ּ�: %d", p, *p, a, &a);
}