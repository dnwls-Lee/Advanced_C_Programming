#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int my_strcmp(char str1[], char str2[]) {
	for (int i = 0; i < 10; i++) {
		if (str1[i] > str2[i])
			return 1;
		else
			return -1;
	}
	return 0;
}

const char* my_strcat(char str1[], char str2[], char str3[]) {
	int Find_Gap = 0, j = 0;
	while (str1[j] != '\0') {
		Find_Gap++;
		j++;
	}
	for (int i = Find_Gap; i < 10; i++) {
		str1[i] = str2[i - Find_Gap];
	}
	for (int i = 0; i < 10; i++) {
		str3[i] = str1[i];
	}
	return str3;
}

const char* my_strcpy(char str1[], char str2[]) {
	for (int i = 0; i < 10; i++) {
		if (str2[i] == '\0')
			str1[i] = '\0';
		else
			str2[i] = str1[i];
	}
	return str1;
}

int main() {
	char str[10], str1[10], str2[20] = "";
	scanf("%s %s", str, str1);
	printf("%d\n", my_strcmp(str, str1));
	scanf("%s %s", str, str1);
	printf("%s\n", my_strcat(str, str1, str2));
	scanf("%s", str);
	printf("%s", my_strcpy(str, str2));
}