// No.1 ���ڿ� ���� �̾� '����'�� ����ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main() {
    while (1) {
        int n,i;
        printf("���̸� �Է��ϼ���: ");
        scanf("%d", &n);
        char* input = (char*)malloc(sizeof(char)*n); // ���ڿ� ũ�� ����

        printf("���� �ϳ��� �Է��ϼ���: ");
        scanf("%s", input);
        if (input[0] == '0' && input[1] == '\0') // 0�� �Է� �� ����
            break;

        printf("�Է��� ������:");
        for (i = 0; i < n; i++) { // ���ڿ� ���̸�ŭ �ݺ�
            if ((int)input[i] >= 48 && (int)input[i] <= 57) // �ƽ�Ű�ڵ� ���
                printf("%d", (int)input[i]-48); // ���������� ���
        }
        printf("\n\n");

        free(input);
    }


    return 0;
}