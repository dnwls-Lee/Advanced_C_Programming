#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main() {
	char* p[3];
	char str[100];
	int size[3];

	for (int i = 0; i < 3; i++) {
		if (i < 2) {
			printf("%d번째 문자열 : ", i + 1);
			scanf("%s", str);

			size[i] = strlen(str);
			p[i] = (char*)malloc((sizeof(char) * size[i]) + 1);
			strcpy(p[i], str);
		}
		else {
			size[i] = size[0] + size[1];
			p[i] = (char*)malloc((sizeof(char) * size[i]) + 1);
			strcpy(p[i], p[0]);
			strcat(p[i], p[1]);
		}
	}

	printf("\n -- 입력된 값 출력(포인터) -- \n");
	for (int i = 0; i < 3; i++) {
		printf("%d : %s\n", i + 1, p[i]);
	}
	for (int i = 0; i < 3; i++) {
		free(p[i]);
	}
}