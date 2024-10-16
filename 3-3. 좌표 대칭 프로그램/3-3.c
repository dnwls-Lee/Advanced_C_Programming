#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Xsymmetry(int x, int y, int *p, int* q) {
	int Rx, Ry;
	if (x > 0)
		*p = x + 1;
	else
		*p = x + 2;

	if (y == 2)
		*q = y - 2;
	else if (y == 1)
		*q = y;
	else if (y == -1)
		*q = y + 3;
	else
		*q = y + 5;
}

void Ysymmetry(int x, int y, int* p, int* q) {
	int Rx, Ry;
	if (x > 0)
		*p = x + 1;
	else
		*p = x + 2;

	if (y == 2)
		*q = y - 2;
	else if (y == 1)
		*q = y;
	else if (y == -1)
		*q = y + 3;
	else
		*q = y + 5;
}

void Originsymmetry(int x, int y, int* p, int* q) {
	int Rx, Ry;
	if (x > 0)
		*p = x + 1;
	else
		*p = x + 2;

	if (y == 2)
		*q = y - 2;
	else if (y == 1)
		*q = y;
	else if (y == -1)
		*q = y + 3;
	else
		*q = y + 5;
}

int main() {
	int x, y, Rx, Ry;
	int* p = &Rx, *q = &Ry;
	scanf("%d %d", &x, &y);
	char arr[4][4];

	if (x > 0)
		Rx = x + 1;
	else
		Rx = x + 2;

	if (y == 2)
		Ry = y - 2;
	else if (y == 1)
		Ry = y;
	else if (y == -1)
		Ry = y + 3;
	else
		Ry = y + 5;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == Ry && j == Rx)
				arr[i][j] = 'X';
			else
				arr[i][j] = 'O';
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	Xsymmetry(-x, y, p, q);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == Ry && j == Rx)
				arr[i][j] = 'X';
			else
				arr[i][j] = 'O';
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	Ysymmetry(x, -y, p, q);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == Ry && j == Rx)
				arr[i][j] = 'X';
			else
				arr[i][j] = 'O';
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	Originsymmetry(-x, -y, p, q);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == Ry && j == Rx)
				arr[i][j] = 'X';
			else
				arr[i][j] = 'O';
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}