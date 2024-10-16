#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

void My_Strcmp(char* arr[]);

int main() {
	char* arr[2];
	char temp[100];
	int size;

	for (int i = 0; i < 2; i++) { // 문자열 2개 입력 받기
		printf("%d 번째 문자열 입력 : ", i + 1);
		gets(temp);
		size = strlen(temp);

		arr[i] = (char*)malloc(sizeof(char) * size + 1);
		strcpy(arr[i], temp);
	}

	My_Strcmp(arr);
}

void My_Strcmp(char* arr[]) { // 대소문자 구분 없이 같은 알파벳인지 확인하는 함수
	int count = 0, size = strlen(arr[0]);

	for (int i = 0; i < size; i++) {
		if ((arr[0][i] == arr[1][i] || arr[0][i] == arr[1][i] + 32) || arr[0][i] == arr[1][i] - 32)
			count++;
	}

	if (count == size)
		printf("True");
	else
		printf("False");
}