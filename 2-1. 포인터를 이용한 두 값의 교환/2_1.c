#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Swap_Var(int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("After Value Swap(in function) : A : %d, B : %d\n", a, b);
}

void Swap_Pointer(int* p, int* q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
	printf("After Value Swap(in function) : A : %d, B : %d\n", *p, *q);
}

int main() {
	int a, b;
	int* p = &a, * q = &b;

	scanf("%d %d", &a, &b);
	printf("Before Swap, A : %d, B : %d\n\n\n", a, b);
	Swap_Var(a, b);
	printf("After Value Swap(in main) : A : %d, B : %d\n\n\n", a, b);
	Swap_Pointer(p, q);
	printf("Reference value swap(in main) : A : %d, B : %d\n", a, b);
}