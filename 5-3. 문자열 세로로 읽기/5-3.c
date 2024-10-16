#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main() {
	int n, Max = 0; // 입력받을 문자열의 개수, 입력받은 문자열 중 가장 길이가 긴 것
	char temp[100]; // 임시로 입력받을 문자열 저장
	printf("입력할 문자열의 개수는? : ");
	scanf("%d", &n);

	char** arr = (char**)malloc(sizeof(char*) * (n + 1)); // 문자열 저장하기 위한 동적할당
	int* Len = (int*)malloc(sizeof(int) * (n + 1)); // 각각의 문자열의 길이를 저장하기 위한 동적할당

	for (int i = 0; i < n; i++) {
		scanf("%s", temp);
		Len[i] = strlen(temp); 

		if (Max < Len[i])
			Max = Len[i];
		arr[i] = (char*)malloc(sizeof(char) * (Len[i] + 1));

		strcpy(arr[i], temp);
	}

	for (int i = 0; i < Max; i++) {
		for (int j = 0; j < n; j++) {
			if (i < Len[j]) // arr[j]의 문자열 길이보다 i번째의 행의 크기가 더 작을 때만 문자열 출력
				printf("%c", arr[j][i]);
		}
	}
}