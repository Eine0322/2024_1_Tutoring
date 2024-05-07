// No.3 두 문자열 비교하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stringCompare(const char* str1, const char* str2) {
    char string1[100] = { 0 };
    char string2[100] = { 0 };

    // 소문자로 바꿔주기
    for (int i = 0; i < 100; i++) {
        if (str1[i] >= 97 && str1[i] <= 122)
            string1[i] = str1[i] - 32;
        else
            string1[i] = str1[i];
        if (str2[i] >= 97 && str2[i] <= 122)
            string2[i] = str2[i] - 32;
        else
            string2[i] = str2[i];
    }

    // 값 빼서 비교하기
    int result = 0;
    for (int i= 0; i < 100; i++) {
        result += string1[i] - string2[i];
    }
    return result;
}

int main() {
    char string1[100] = { 0 };
    char string2[100] = { 0 };

    printf("첫 번째 문자열을 입력하시오 : ");
    scanf("%s", string1);
    printf("두 번째 문자열을 입력하시오 : ");
    scanf("%s", string2);

    if (stringCompare(string1, string2) < 0) {
        printf("첫 번째 문자열이 먼저 온다.\n");
    }
    else if (stringCompare(string1, string2) > 0) {
        printf("두 번째 문자열이 먼저 온다.\n");
    }
    else {
        printf("같은 문자열이다.\n");
    }
}
