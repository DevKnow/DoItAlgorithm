#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "ArrayIntQueue.h"

int main() {
	ArrayIntQueue a;
	if (Initialize(&a, 10) == -1) {
		puts("큐 생성에 실패했습니다.");
		return -1;
	}

	int menu, x;
	while (1) {
		printf("현재 데이터: %d / %d\n", Size(&a), Capacity(&a));
		printf("(1)인큐 (2)디큐 (0)프로그램종료: "); scanf("%d", &menu);
		if (menu == 0) break;
		switch (menu)
		{
		case 1:
			printf("인큐할 값: "); scanf("%d", &x);
			if (Enqueue(&a, x) == -1)
				puts("\a인큐에 실패했습니다.");
			break;
		case 2:
			if (Dequeue(&a, &x) == -1)
				puts("\a디큐에 실패했습니다.");
			else
				printf("디큐한 값: %d\n", x);
			break;
		}
	}

	return 0;
}