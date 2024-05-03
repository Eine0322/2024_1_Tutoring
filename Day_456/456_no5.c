// No.5 로마숫자
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int squ(int a, int b) {
	int result=1;
	for (int i = 0; i < b; i++) {
		result *= a;
	}
	return result;
}

int main() {
	int num,jari;
	int count[3][4] = { 0 };
	int math[3];
	int total_count = 0;
	printf("변환 수 입력: ");
	scanf("%d", &num);
	int n = num;
	for (int i = 2; i >= 0; i--) {
		jari = squ(10, i);
		math[2-i] =(int)(num / jari)*jari;
		if (num >= 9* jari){
			count[2 - i][0]++;
			num %= 9 * jari;
		}
		else if (num >= 5 * jari) {
			count[2 - i][1]++;
			num %= 5 * jari;
		}
		else if (num >= 4 * jari) {
			count[2 - i][2]++;
			num %= 4 * jari;
		}
		else if (num>=1* jari) {
			count[2-i][3] = num / (1 * jari);
			num %= 1 * jari;
		}
		total_count += (count[2 - i][1] + count[2 - i][3] + 2*count[2-i][0] + 2*count[2-i][2]);
	}

	char* rom = (char*)malloc(sizeof(char) * total_count + 1);

	int stack = 0;
	char ten, five, one;
	for (int i = 0; i < 3; i++) {
		if (i == 0) { ten = 'M', five = 'D', one = 'C'; }
		else if (i == 1) { ten = 'C', five = 'L', one = 'X'; }
		else { ten = 'X', five = 'V', one = 'I'; }
		for (int j = 0; j < 4; j++) {
			if (count[i][j] != 0) {
				if (j == 0) {
					rom[stack] = one;
					rom[stack + 1] = ten;
					stack += 2;
				}
				else if (j == 1) {
					rom[stack] = five;
					stack++;
				}
				else if (j == 2) {
					rom[stack] = one;
					rom[stack+1] = five;
					stack += 2;
				}
				else {
					for (int k = 0; k < count[i][j]; k++) {
						rom[stack] = one;
						stack++;
					}
				}
			}
		}
	}
	rom[stack] = '\0';
	printf("%d=%d+%d+%d=%s, %d",n,math[0],math[1],math[2],rom,total_count);
}