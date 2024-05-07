// No.10 소수 판별하기
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
    printf("정수 입력: ");
    scanf("%d", &num);

    if (isPrime(num))
        printf("%d는 소수입니다.\n", num);
    else
        printf("%d는 소수가 아닙니다.\n", num);

    return 0;
}