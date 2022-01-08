#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	int* a;
	int na;
	printf("요소 개수: ");
	scanf("%d", &na);
	a = (int*)calloc(na, sizeof(int));
	if (a == NULL)
		puts("메모리 할당에 실패했습니다.");
	else {
		printf("%d개의 정수를 입력하세요.\n",na);
		for (i = 0; i < na; i++) {
			printf("a[%d]: ", i);
			scanf("%d", &a[i]);
		}
		puts("각 요솟값은 아래와 같습니다.");
		for (i = 0; i < na; i++)
			printf("a[%d]=%d\n", i, a[i]);
		free(a);
	}

	return 0;
}