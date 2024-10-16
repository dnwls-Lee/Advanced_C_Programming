#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Sort_Ascending(int arr[]);
void Sort_Descending(int arr[]);

int main() {
	int arr[100];
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++) {
		arr[i] = (rand() % 100) + 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j])
				i--;
		}
	}
	printf("Before : ");
	for (int i = 0; i < 100; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	Sort_Ascending(arr);
	printf("AfterAscending : ");
	for (int i = 0; i < 100; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	Sort_Descending(arr);
	printf("AfterDescending : ");
	for (int i = 0; i < 100; i++) {
		printf("%d ", arr[i]);
	}
}

void Sort_Ascending(int arr[]) {
	int temp;
	for (int i = 0; i < 100; i++) {
		for (int j = i; j < 100; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void Sort_Descending(int arr[]) {
	int temp;
	for (int i = 0; i < 100; i++) {
		for (int j = i; j < 100; j++) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}