// No.3 �� ���ڿ� ���ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stringCompare(const char* str1, const char* str2) {
    char string1[100] = { 0 };
    char string2[100] = { 0 };

    // �ҹ��ڷ� �ٲ��ֱ�
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

    // �� ���� ���ϱ�
    int result = 0;
    for (int i= 0; i < 100; i++) {
        result += string1[i] - string2[i];
    }
    return result;
}

int main() {
    char string1[100] = { 0 };
    char string2[100] = { 0 };

    printf("ù ��° ���ڿ��� �Է��Ͻÿ� : ");
    scanf("%s", string1);
    printf("�� ��° ���ڿ��� �Է��Ͻÿ� : ");
    scanf("%s", string2);

    if (stringCompare(string1, string2) < 0) {
        printf("ù ��° ���ڿ��� ���� �´�.\n");
    }
    else if (stringCompare(string1, string2) > 0) {
        printf("�� ��° ���ڿ��� ���� �´�.\n");
    }
    else {
        printf("���� ���ڿ��̴�.\n");
    }
}
