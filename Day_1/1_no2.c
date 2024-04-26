#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char string[100] = { 0 };
	char add[100] = { 0 };
	int i;
	printf("영문 문자열을 입력하시오 : ");
	
	scanf("%[^\n]s", add); // 공백 포함 문자열 받기

	printf("입력된 문자열 : %s\n", add);

	for (i = 0; i < 100; i++) { 
		if (add[i] >= 65 && add[i] <= 90)
			string[i] = add[i] + 32; // 소문자 -> 대문자 새로운 배열에 저장
		else if (add[i] >= 97 && add[i] <= 122) 
			string[i] = add[i] - 32; // 대문자 -> 소문자 새로운 배열에 저장
		else
			string[i] = add[i]; // 공백, 숫자 등 그대로 새로운 배열에 저장
	}
	printf("수정된 문자열 : %s\n", string);
}