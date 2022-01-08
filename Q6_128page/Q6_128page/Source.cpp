#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

long long_cmpr(const long* a, const long* b) {
	if (*a < *b) return 1;
	else if (*a > *b) return -1;
	else return 0;
}

int main(void) {
	long i, nx, ky;
	long* x;
	long* p=NULL;
	puts("bsearch �Լ��� ����Ͽ� �˻�");
	printf("��� ����: ");
	scanf("%d", &nx);
	x = (long*)malloc(sizeof(long) * nx);
	puts("������������ �Է��ϼ���.\n");
	printf("x[0]: ");
	scanf("%d", &x[0]);
	for (i = 1; i < nx; i++) {
		do {
			printf("x[%d]: ", i);
			scanf("%d", &x[i]);
		} while (x[i]>x[i-1]);
	}
	printf("�˻���: ");
	scanf("%d", &ky);
	if(x!=NULL)
		p = (long*)bsearch(&ky, x, nx, sizeof(long), (int(*)(const void*, const void*))long_cmpr);
	if (p == NULL)
		puts("�˻��� �����߽��ϴ�");
	else
		printf("%d��(��) x[%d]�� �ֽ��ϴ�\n", ky, p-x);

	free(x);

	return 0;
}