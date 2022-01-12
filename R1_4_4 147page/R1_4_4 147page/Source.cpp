#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntQueue.h"

int main() {
	IntQueue que;

	if (Initialize(&que, 8) == -1) {
		puts("큐 생성에 실패했습니다.");
		return -1;
	}

	int m, x;
	while (1) {
		printf("현재 데이터 수: %d / %d\n", Size(&que), Capacity(&que));
		printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (0)종료: "); scanf("%d", &m);

		if (m == 0) break;
		switch (m) {
		case 1:
			printf("인큐할 값: "); scanf("%d", &x);
			if(Enque(&que, x)==-1)
				puts("\a인큐 실패");
			break;
		case 2:
			if (Deque(&que, &x) == -1)
				puts("\a디큐 실패");
			else
				printf("디큐 결과: %d\n", x);
			break;
		case 3:
			if (Peek(&que, &x) == -1)
				puts("\a피크 실패");
			else
				printf("피크 결과: %d\n", x);
			break;
		case 4:
			Print(&que);
			break;
		}
	}

	Terminate(&que);
	return 0;
}