#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int Num, Cur_Num, Chun = 1000, Cnt, Cur = 1;
	int RomType[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	char* RomChar[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	char* arr = (char*)malloc(sizeof(char) * Cur);
	arr[0] = '\0';

	printf("로마숫자로 변환할 숫자 입력(1000 이하의 수) : ");
	scanf("%d", &Num);
	Cur_Num = Num;
	printf("%d = ", Num);

	for (int i = 0; i < 14; i++) {
		Cnt = Num / RomType[i];
		if (i % 2 == 1 && Cnt != 0) {
			Cur += 2;
			arr = (char*)realloc(arr, sizeof(char) * Cur);
			strcat(arr, RomChar[i]);
			Num = Num % RomType[i];
		}
		else if (i % 2 == 0 && Cnt != 0) {
			for (int j = 0; j < Cnt; j++) {
				Cur++;
				arr = (char*)realloc(arr, sizeof(char) * Cur);
				strcat(arr, RomChar[i]);
			}
			Num = Num % RomType[i];
		}
	}

	for (int i = 0; i < 4; i++) {
		if (Cur_Num / Chun != 0 && i != 3 && Cur_Num != 1000) {
			printf("%d + ", (Cur_Num / Chun) * Chun);
		}
		else if (Cur_Num / Chun != 0 && i == 3 && Cur_Num != 1000) {
			printf("%d = ", (Cur_Num / Chun) * Chun);
		}
		Cur_Num %= Chun;
		Chun /= 10;
	}
	printf("%s, %d", arr, Cur - 1);

	free(arr);
}