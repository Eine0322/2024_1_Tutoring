// No.10 �Ҽ� �Ǻ��ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isPrime(int num) {
    int count=0;
    for (int i = 2; i < num; i++) {
        if (num / i == 0) {
            count++;
        }
    }
    if (num == 1)
        return 0;
    else if (count == 0)
        return 1;
    else
        return 0;
}

int main() {
    int num;
    printf("���� �Է�: ");
    scanf("%d", &num);

    if (isPrime(num))
        printf("%d�� �Ҽ��Դϴ�.\n", num);
    else
        printf("%d�� �Ҽ��� �ƴմϴ�.\n", num);

    return 0;
}