#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Swap_Var(int arr[]) {
	int temp;
	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
	printf("Swap by Index : %d %d\n\n", arr[0], arr[1]);
}

void Swap_Pointer(int* p, int* q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
	printf("Swap by Pointer : %d %d\n", *p, *q);
}

int main() {
	int arr[2];
	int* p = &arr[0], *q = &arr[1]; 
	for (int i = 0; i < 2; i++)
		scanf("%d", &arr[i]);
	printf("Before Swap : %d %d\n", arr[0], arr[1]);
	Swap_Var(arr);
	for (int i = 0; i < 2; i++)
		scanf("%d", &arr[i]);
	printf("Before Swap : %d %d\n", arr[0], arr[1]);
	Swap_Pointer(p, q);
}