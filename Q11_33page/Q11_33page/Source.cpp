#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
	int ten = 1;
	for (int i = 1;; i*=10) {
		if (n / (i * 10) > 0) ten++;
		else break;
	}

	printf("그 수는 %d자리 입니다.", ten);

	return 0;
}