#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStack.h"

int main() {
	IntStack s;
	if (Initialize(&s, 10) == -1) {
		puts("스택 생성에 실패했습니다.");
		return 1;
	}

	while (1) {
		int menu, x,index,ptr, stack;
		printf("현재 총 데이터 수: %d / %d\n", Size(&s,PTR_A)+ Size(&s, PTR_B), Capacity(&s));
		printf("(1) 푸시 (2) 팝 (3) 피크 (4) 출력 (5) 검색 (6) 초기화 (0) 종료: ");
		scanf("%d", &menu);

		if (menu == 0) break;
		switch (menu) {
		case 1:
			printf("어떤 스택? (A스택은 1, B스택은 2): ");
			scanf("%d", &ptr);
			printf("데이터: ");
			scanf("%d", &x);
			if (Push(&s, x, ptr) == -1)
				puts("\a푸시에 실패했습니다.");
			break;
		case 2:
			printf("어떤 스택? (A스택은 1, B스택은 2): ");
			scanf("%d", &ptr);
			if (Pop(&s, &x, ptr) == -1)
				puts("\a푸시에 실패했습니다.");
			else
				printf("팝데이터는 %d입니다.\n", x);
			break;

		case 3:
			printf("어떤 스택? (A스택은 1, B스택은 2): ");
			scanf("%d", &ptr);
			if (Peek(&s, &x, ptr) == -1)
				puts("\a피크에 실패했습니다.");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;
		case 4:
			printf("어떤 스택? (A스택은 1, B스택은 2): ");
			scanf("%d", &ptr);
			Print(&s,ptr);
			break;
		case 5:
			printf("검색할 데이터: ");
			scanf("%d", &x);
			index=Search(&s, x, stack);
			if (index == -1)
				puts("\a검색에 실패했습니다.");
			else
				printf("해당 데이터는 %c스택의 %d번째 인덱스에 있습니다.\n", stack==1? 'A' : 'B', index);
			break;
		case 6:
			puts("스택을 청소합니다.");
			Clear(&s);
			break;
		}
	}
	Terminate(&s);

	//int temp;
	//scanf("%d", &temp);
	return 0;
}