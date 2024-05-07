// No.5 로마숫자 변환
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main() {
	int num;
	printf("변환 수 입력: ");
	scanf("%d", &num);
	int num_save = num;
	// 초기 rom 배열 동적할당
	char* rom = (char*)malloc(sizeof(char) * 2);
	int num_count[3];
	char ten, five, one;
	int N=100;
	int count = 1;
	int rc = 0;
	// 100, 10, 1 자리수 나눠 출력
	for (int i = 0; i <= 2;i++) {
		num_count[i] = num - (num % N);
		// 단위 수 별 기호 지정
		if (N == 100) { ten = 'M'; five = 'D'; one = 'C'; }
		else if (N == 10) { ten = 'C'; five = 'L'; one = 'X'; }
		else { ten = 'X'; five = 'V'; one = 'I'; }
		// 동적할당 확장, 특수 숫자 채우기 (9,5,4)
		if (num >= (9 * N)) {
			count += 2;
			rom= (char*)realloc(rom, sizeof(char) * count);
			rom[rc++] = one;
			rom[rc++] = ten;
			num %= (9 * N);
		}
		else if (num >= (5 * N)) {
			count += 1;
			rom = (char*)realloc(rom, sizeof(char) * count);
			rom[rc++] = five;
			num %= (5 * N);
		}
		else if (num >= (4 * N)) {
			count += 2;
			rom = (char*)realloc(rom, sizeof(char) * count);
			rom[rc++] = one;
			rom[rc++] = five;
			num %= (4 * N);
		}
		// 남은 숫자 나눠 작은 단위로 채우기
		if (num>= N) {
			count += (int)(num / (1 * N));
			rom = (char*)realloc(rom, sizeof(char) * count);
			for (int k = 0; k < (int)(num / (1 * N)); k++) {
				rom[rc++] = one;
			}
			num %= N;
		}
		N /= 10;
	}
	// 공문자 삽입, 결과 출력
	rom[count - 1] = '\0';
	printf("%d=%d+%d+%d=%s, %d", num_save, num_count[0], num_count[1], num_count[2], rom, count-1);
	free(rom);
}