#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
float pie = 3.14

float Cal_Round(int* p) {
	return *p * pie * 2;
}

float Cal_Extent(int* p) {
	return *p * *p * pie;
}

int main() {
	int a;
	int* p = &a;
	printf("넓이/둘레를 구할 원의 반지름을 입력하시오 : ");
	scanf("%d", &a);

	printf("입력한 반지름 %d 에 대한\n원의 둘레는 : %f\n원의 넓이는 : %f", a, Cal_Round(p), Cal_Extent(p));
}