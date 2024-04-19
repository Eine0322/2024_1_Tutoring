// No.2 ���� ���� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
int arr[20]; // �迭 ����

void merge(int left, int right) { // �������� �Լ�
	int l = left; // �ʱ� left ��(�迭�� ���� ���� ��)��, ���� l �� �и�
	int r = right;
	int mid = ((l + r) / 2) + 1;
	int m = mid; // �ʱ� mid��(�迭�� �߰�+1��, �� ��° �迭�� ���� ���� ��)�� ���� m �� �и�
	int count = l;
	int i;
	int sort[20] = { 0 }; // �����ϱ� ���� �ӽ� �迭 ����

	while (count <= right) { // ���������� �迭��ŭ �ݺ�
		if (l == mid) {  // ���� �迭�� ��� ���ĵǾ��� ��, ������ �迭�� ������� sort�� ���ĵǰ� ��
			sort[count] = arr[m];
			m++;
		}
		else if (m == r + 1) { // ������ �迭�� ��� ���ĵǾ��� ��, ���� �迭�� ������� sort�� ���ĵǰ� ��
			sort[count] = arr[l];
			l++;
		}
		else if (arr[l] < arr[m]) { // �� �迭�� ù ��° ��� ���� ��, ���� ���� sort ���� ������� ����
			sort[count] = arr[l];
			l++;
		}
		else if (arr[l] >= arr[m]) {
			sort[count] = arr[m];
			m++;
		}
		count++; // sort �迭�� ������� ���ĵǰ� �� (�ʱⰪ: ������ �迭�� ���� ���� ��)
	}

	for (i = left; i <= right; i++) {
		arr[i] = sort[i]; // sort �迭�� �ӽ÷� �����ص� ���� arr �迭�� �Ű���
	}
}

void merge_sort(int left, int right) { // ���������� ���� ū �迭�� �� ���� �ɰ��ִ� �Լ�
	if (left >= right) // �迭�� ũ�Ⱑ 1�� �� ��� ����
		return;
	int mid = (left + right) / 2; // �迭�� �߰��� ����
	merge_sort(left, mid); // ù ��° �迭
	merge_sort(mid + 1, right); // �� ��° �迭
	merge(left, right); // ù ��°, �� ��° �迭�� ������ (���ĵ� �迭)
}

int main(void) {
	srand(time(0));
	int i;

	for (i = 0; i < 20; i++) {
		*(arr + i) = rand() % 201 - 100; //���� ����, �迭 ����
	}
	for (i = 0; i < 20; i++) { // ���� �� �迭 ���
		printf("%d ", arr[i]);
	}

	merge_sort(0, 19); // ��������

	printf("\n");
	for (i = 0; i < 20; i++) { // ���ĵ� �迭 ���
		printf("%d ", arr[i]);
	}
}