// No.9 ���� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sortArray(int* arr, int size) {
    int tmp;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main() {
    int size;
    printf("�迭 ũ�� �Է�: ");
    scanf("%d", &size);

    int arr[100];
    printf("���� �迭 �Է�: ");
    for (int i = 0; i < size; i++) {
        scanf(" %d", &arr[i]);
    }

    sortArray(arr, size);

    printf("���ĵ� �迭: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}