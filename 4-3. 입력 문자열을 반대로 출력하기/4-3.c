#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main() {
	char* p[3];
	char imsi[100], temp;
	int size;

	for (int i = 0; i < 3; i++) {
		printf("%d번째 문자열 : ", i + 1);
		gets(imsi);

		size = strlen(imsi);
		p[i] = (char*)malloc((sizeof(char) * size) + 1);

		for (int j = 0; j < size / 2; j++) {
			temp = imsi[j];
			imsi[j] = imsi[size - j - 1];
			imsi[size - j - 1] = temp;
		}

		strcpy(p[i], imsi);
	}

	printf("\n -- 입력과 반대로 출력(포인터) -- \n");
	for (int i = 2; i >= 0; i--) {
		printf("%d : %s\n", i + 1, p[i]);
	}
	for (int i = 0; i < 3; i++) {
		free(p[i]);
	}
}