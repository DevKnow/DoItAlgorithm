#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 10

int main() {
	int i, a[N], cnt = 0, retry;
	puts("������ �Է��ϼ���: ");
	do{
		printf("%d��° ����: ", cnt + 1); scanf("%d", &a[cnt++ % N]);
		printf("���?(1)�� (2)�ƴϿ�: "); scanf("%d", &retry);
	} while (retry == 1);
	i = cnt - N;
	if (i < 0) i = 0;
	for (; i < cnt; i++) {
		printf("%2d��° ���� = %d\n", (i + 1 )% N, a[i % N]);
	}
	return 0;
}