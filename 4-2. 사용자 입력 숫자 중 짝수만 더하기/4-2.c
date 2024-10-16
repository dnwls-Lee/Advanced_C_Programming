#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main() {
	int* p;
	int hap = 0, cnt = 0, data;
	p = (int*)malloc(sizeof(int) * 1);

	for (int i = 2; ; i++) {
		printf("%d 번째 숫자 : ", i - 1);
		scanf("%d", &data);

		if (data != 0)
			p = (int*)realloc(p, sizeof(int) * i);
		else
			break;

		p[i - 2] = data;
		printf("%d %d\n", i - 2, p[i - 2]);
		cnt++;
	}

	for (int i = 0; i < cnt; i++) {
		printf("%d %d\n", i, p[i]);
		if(p[i] % 2 == 0)
			hap += p[i];
	}


	free(p);
}