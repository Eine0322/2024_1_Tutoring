// No.6 ������ ����Ͽ� �� ���� �� ��ȯ�ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int tmp,a,b;
	int* p = &a;
	int* q = &b;

	printf("��ȯ �� a b: ");
	scanf("%d %d", p, q);
	tmp = *p;
	*p = *q;
	*q=tmp;
	printf("��ȯ �� a b: %d %d", a, b);
}