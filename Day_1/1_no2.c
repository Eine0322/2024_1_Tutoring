#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char string[100] = { 0 };
	char add[100] = { 0 };
	int i;
	printf("���� ���ڿ��� �Է��Ͻÿ� : ");
	
	scanf("%[^\n]s", add); // ���� ���� ���ڿ� �ޱ�

	printf("�Էµ� ���ڿ� : %s\n", add);

	for (i = 0; i < 100; i++) { 
		if (add[i] >= 65 && add[i] <= 90)
			string[i] = add[i] + 32; // �ҹ��� -> �빮�� ���ο� �迭�� ����
		else if (add[i] >= 97 && add[i] <= 122) 
			string[i] = add[i] - 32; // �빮�� -> �ҹ��� ���ο� �迭�� ����
		else
			string[i] = add[i]; // ����, ���� �� �״�� ���ο� �迭�� ����
	}
	printf("������ ���ڿ� : %s\n", string);
}