#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func_print(char str[][100]);
void func_sort(char str[][100], char Array[]);
void input_char(char str[][100]);

int main() {
	char str[100][100];
	input_char(str);
}

void input_char(char str[][100]) {
	char Array[1000];
	for (int i = 0; i < 10; i++) {
		printf("%d번째 문자열을 입력하세요 : ", i + 1);
		scanf("%s", str[i]);
	}
	printf("정렬 방식은? : ");
	scanf("%s", Array);

	func_sort(str, Array);
}

void func_sort(char str[][100], char Array[]) {
	char temp[100];
	if ((strcmp(Array, "오름차순") == 0)) {
		char temp[100];
		for (int i = 0; i < 10; i++) {
			for (int j = i + 1; j < 10; j++) {
				if (strcmp(str[i], str[j]) > 0) { 
					strcpy(temp, str[i]);
					strcpy(str[i], str[j]);
					strcpy(str[j], temp);
				}
			}
		}
		func_print(str);
	}
	else {
		for (int i = 0; i < 10; i++) {
			for (int j = i; j < 10; j++) {
				if (strcmp(str[i], str[j]) < 0) {
					strcpy(temp, str[i]);
					strcpy(str[i], str[j]);
					strcpy(str[j], temp);
				}
			}
		}
		func_print(str);
	}
}

void func_print(char str[][100]) {
	for(int i = 0; i < 10; i++)
		printf("%s\n", str[i]);
}