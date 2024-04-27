// No.1 문자열 정수 뽑아 '정수'로 출력하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main() {
    while (1) {
        int n,i;
        printf("길이를 입력하세요: ");
        scanf("%d", &n);
        char* input = (char*)malloc(sizeof(char)*n); // 문자열 크기 지정

        printf("정수 하나를 입력하세요: ");
        scanf("%s", input);
        if (input[0] == '0' && input[1] == '\0') // 0만 입력 시 종료
            break;

        printf("입력한 정수는:");
        for (i = 0; i < n; i++) { // 문자열 길이만큼 반복
            if ((int)input[i] >= 48 && (int)input[i] <= 57) // 아스키코드 사용
                printf("%d", (int)input[i]-48); // 정수형으로 출력
        }
        printf("\n\n");

        free(input);
    }


    return 0;
}