// No.8 swap �Լ� �����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* num1, int* num2) {
    int tmp;
    tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

int main() {
    int num1, num2;
    printf("�� ���� �Է�: ");
    scanf("%d %d", &num1, &num2);

    printf("Swap ��: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1,&num2);
    printf("Swap ��: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}