#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main() {
	int Len;
	char** arr = (char**)malloc(sizeof(char*) * 3);
	char temp[100];
	scanf("%s", temp);

	Len = strlen(temp);

	for (int i = 0; i < 3; i++) {
		arr[i] = (char*)malloc(sizeof(char) * (Len + 1));
		strcpy(arr[i], temp);
	}

	for (int i = 0; i < Len; i++) {
		if (arr[1][i] >= 'a' && arr[1][i] <= 'z')
			arr[1][i] = arr[1][i] - 32;
	}

	for (int i = 0; i < Len; i++) {
		if (arr[2][i] >= 'A' && arr[2][i] <= 'Z')
			arr[2][i] = arr[2][i] + 32;
	}

	printf("%s\n", arr[1]);
	printf("%s", arr[2]);

	free(arr);
}