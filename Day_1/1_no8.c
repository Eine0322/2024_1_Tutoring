// No.8 swap 함수 만들기
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
    printf("두 정수 입력: ");
    scanf("%d %d", &num1, &num2);

    printf("Swap 전: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1,&num2);
    printf("Swap 후: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}