/*
 ============================================================================
 Name        : alds1_4_c_dictionary.c
 Author      : lovesaemi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

//#define M 1046527
#define MAX 244140625
#define NIL (-1)
#define L 14

char H[MAX];
char s[13];


int getChar(char ch) {
	if (ch == 'A')
		return 1;
	else if (ch == 'C')
		return 2;
	else if (ch == 'G')
		return 3;
	else if (ch == 'T')
		return 4;
	else
		return 0;
}
long long getKey() {
	long long sum = 0, p = 1, i, l;
	for (i = 0, l = strlen(s); i < l; i++) {
		sum += p * (getChar(s[i]));
		p *= 5;
	}
	return sum;
}

int find() {
	int key = getKey();
	if (H[key]) {
		return 1;
	}
	return 0;
}
void insert() {
	H[getKey()] = 1;
}

int main(void) {
	int i, n;
	char com[9];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %s", com, s);
		if (com[0] == 'i') {
			insert();
		} else {
			if (find()) {
				printf("yes\n");
			} else {
				printf("no\n");
			}
		}
	}
	return 0;
}
