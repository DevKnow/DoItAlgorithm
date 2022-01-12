#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 10

int main() {
	int i, a[N], cnt = 0, retry;
	puts("정수를 입력하세요: ");
	do{
		printf("%d번째 정수: ", cnt + 1); scanf("%d", &a[cnt++ % N]);
		printf("계속?(1)예 (2)아니요: "); scanf("%d", &retry);
	} while (retry == 1);
	i = cnt - N;
	if (i < 0) i = 0;
	for (; i < cnt; i++) {
		printf("%2d번째 정수 = %d\n", (i + 1 )% N, a[i % N]);
	}
	return 0;
}