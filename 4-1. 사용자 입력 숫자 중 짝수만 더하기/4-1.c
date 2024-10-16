#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main() {
	int* p;
	int i, cnt, hap = 0;

	printf("입력할 개수는? : ");
	scanf("%d", &cnt);

	p = (int*)malloc(sizeof(int) * cnt);

	for (int i = 0; i < cnt; i++) {
		printf("%d번째 숫자 입력 : ", i + 1);
		scanf("%d", &p[i]);

		hap = hap + p[i];
	}

	printf("입력 숫자의 합 => %d\n", hap);

	free(p);
}
