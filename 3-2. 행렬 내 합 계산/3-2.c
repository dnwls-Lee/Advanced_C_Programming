#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Sum_Array(int (*p)[8]) {
	for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 7 - 2 * j; k += 2 + (2 * j)){
			if(j == 2)
				*(*(p + j + 1) + k) = *(*(p + j) + k) + *(*(p + j) + 4);
			else
				*(*(p + j + 1) + k) = *(*(p + j) + k) + *(*(p + j) + k + j + 1);
		}
		printf("\n");
	}
	return *(*(p + 3) + 0);
}

int main() {
	int arr[4][8] = {0};
	int (*p)[8] = arr;
	for (int i = 0; i < 8; i++) {
		scanf("%d", &arr[0][i]);
	}

	printf("%d", Sum_Array(p));
}