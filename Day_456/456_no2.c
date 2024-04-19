// No.2 병합 정렬 구현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
int arr[20]; // 배열 지정

void merge(int left, int right) { // 병합정렬 함수
	int l = left; // 초기 left 값(배열의 가장 왼쪽 값)과, 변수 l 값 분리
	int r = right;
	int mid = ((l + r) / 2) + 1;
	int m = mid; // 초기 mid값(배열의 중간+1값, 두 번째 배열의 가장 왼쪽 값)과 변수 m 값 분리
	int count = l;
	int i;
	int sort[20] = { 0 }; // 정렬하기 위한 임시 배열 지정

	while (count <= right) { // 병합정렬할 배열만큼 반복
		if (l == mid) {  // 왼쪽 배열은 모두 정렬되었을 때, 오른쪽 배열이 순서대로 sort에 정렬되게 함
			sort[count] = arr[m];
			m++;
		}
		else if (m == r + 1) { // 오른쪽 배열은 모두 정렬되었을 때, 왼쪽 배열이 순서대로 sort에 정렬되게 함
			sort[count] = arr[l];
			l++;
		}
		else if (arr[l] < arr[m]) { // 두 배열의 첫 번째 요소 값을 비교, 작은 것을 sort 값에 순서대로 정렬
			sort[count] = arr[l];
			l++;
		}
		else if (arr[l] >= arr[m]) {
			sort[count] = arr[m];
			m++;
		}
		count++; // sort 배열에 순서대로 정렬되게 함 (초기값: 병합할 배열의 가장 왼쪽 값)
	}

	for (i = left; i <= right; i++) {
		arr[i] = sort[i]; // sort 배열에 임시로 정렬해둔 값을 arr 배열로 옮겨줌
	}
}

void merge_sort(int left, int right) { // 병합정렬을 위해 큰 배열을 두 개로 쪼개주는 함수
	if (left >= right) // 배열의 크기가 1이 될 경우 중지
		return;
	int mid = (left + right) / 2; // 배열의 중간값 설정
	merge_sort(left, mid); // 첫 번째 배열
	merge_sort(mid + 1, right); // 두 번째 배열
	merge(left, right); // 첫 번째, 두 번째 배열을 합쳐줌 (정렬된 배열)
}

int main(void) {
	srand(time(0));
	int i;

	for (i = 0; i < 20; i++) {
		*(arr + i) = rand() % 201 - 100; //난수 생성, 배열 저장
	}
	for (i = 0; i < 20; i++) { // 정렬 전 배열 출력
		printf("%d ", arr[i]);
	}

	merge_sort(0, 19); // 병합정렬

	printf("\n");
	for (i = 0; i < 20; i++) { // 정렬된 배열 출력
		printf("%d ", arr[i]);
	}
}