#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func_print(char str[]);
void func_sort(char str[], char Array[]);
void input_char(char str[]);

int main() {
	char str[100];
	input_char(str);
}

void func_print(char str[][100]) {
	for (int i = 0; i < 10; i++) {
		printf("%s", str[i]);
		printf("\n");
	}
}

void func_sort(char str[], char Array[]) {
	char temp;
	if ((strcmp(Array, "오름차순") == 0)) {
		for (int i = 0; i < len; i++) {
			for (int j = i; j < len; j++) {
				if (str[i] > str[j]) {
					temp = str[i];
					str[i] = str[j];
					str[j] = temp;
				}
			}
		}
		func_print(str);
	}
	else {
		for (int i = 0; i < len; i++) {
			for (int j = i; j < len; j++) {
				if (str[i] < str[j]) {
					temp = str[i];
					str[i] = str[j];
					str[j] = temp;
				}
			}
		}
		func_print(str);
	}
}

void input_char(char str[]) {
	char Array[1000];
	for (int i = 0; i < 10; i++) {
		printf("문자열을 입력하세요 : ");
		scanf("%s", str[i]);
	}
	printf("정렬 방식은? : ");
	scanf("%s", Array);

	func_sort(str, Array);
}