// No.7 ���ڿ� ���� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void reverseString(char* str) {
    char tmp[100];
    for (int i = 0; i < strlen(str); i++) 
        tmp[i] = str[strlen(str)-1-i];
    for (int i = 0; i < strlen(str); i++)
        str[i] = tmp[i];
    str[strlen(str)] = '\0';
}

int main() {
    char str[100];
    printf("���ڿ� �Է�: ");
    scanf("%s", str);

    reverseString(str);

    printf("������ ���ڿ�: %s\n", str);

    return 0;
}