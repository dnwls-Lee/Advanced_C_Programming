#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Find_PrimeNum(int arr[]) {
	for (int i = 2; i < 31; i++) {
		if (arr[i] != 0) {
			for (int j = i + 1; j < 31; j++) {
				if (arr[j] % arr[i] == 0) {
					arr[j] = 0;
				}
			}
		}
	}
}

int main() {
	int arr[31];
	for (int i = 2; i < 31; i++) {
		arr[i] = i;
	}
	Find_PrimeNum(arr);
	for (int i = 2; i < 31; i++) {
		if(arr[i] !=  0)
			printf("%d ", arr[i]);
	}
}