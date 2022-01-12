#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStack.h"

int main() {
	IntStack s;
	if (Initialize(&s, 10) == -1) {
		puts("스택 생성에 실패했습니다.");
		return 0;
	}

	while (1) {
		int menu, x, result, stackName;
		printf("스택 데이터수: %d / %d\n", Size(&s, STACK_A)+ Size(&s, STACK_B), Capacity(&s));
		printf("(1)푸시 (2)팝 (3)피크 (4)출력 (5)검색 (6)초기화 (0)종료: "); scanf("%d", &menu);


		if (menu == 0) break;
		switch (menu) {
		case 1:
			printf("푸시할 스택(A는 1 B는 2): "); scanf("%d", &stackName);
			printf("푸시할 데이터: "); scanf("%d", &x);
			if (Push(&s, x, stackName) == -1)
				puts("\a오류: 푸시에 실패했습니다.");
			break;
		case 2:
			printf("팝할 스택(A는 1 B는 2): "); scanf("%d", &stackName);
			if (Pop(&s, &x, stackName) == -1)
				puts("\a오류: 팝에 실패했습니다.");
			else
				printf("팝 데이터는 %d입니다.\n", x);
			break;
		case 3:
			printf("피크할 스택(A는 1 B는 2): "); scanf("%d", &stackName);
			if (Peek(&s, &x, stackName) == -1)
				puts("\a오류: 피크에 실패했습니다.");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;
		case 4:
			Print(&s);
			break;
		case 5:
			printf("검색할 데이터: "); scanf("%d", &x);
			result = Search(&s, x, &stackName);
			if (result == -1)
				puts("\a오류: 검색에 실패했습니다.");
			else
				printf("%d는 %d번째(%c스택)에 있습니다.\n", x, result, stackName == 1 ? 'A' : 'B');
			break;
		case 6:
			Clear(&s);
			break;
		}
	}
	Terminate(&s);

	return 0;
}