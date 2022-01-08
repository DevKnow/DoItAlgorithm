#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStack.h"

int main() {
	IntStack s;
	if (Initialize(&s, 10) == -1) {
		puts("���� ������ �����߽��ϴ�.");
		return 1;
	}

	while (1) {
		int menu, x,index,ptr, stack;
		printf("���� �� ������ ��: %d / %d\n", Size(&s,PTR_A)+ Size(&s, PTR_B), Capacity(&s));
		printf("(1) Ǫ�� (2) �� (3) ��ũ (4) ��� (5) �˻� (6) �ʱ�ȭ (0) ����: ");
		scanf("%d", &menu);

		if (menu == 0) break;
		switch (menu) {
		case 1:
			printf("� ����? (A������ 1, B������ 2): ");
			scanf("%d", &ptr);
			printf("������: ");
			scanf("%d", &x);
			if (Push(&s, x, ptr) == -1)
				puts("\aǪ�ÿ� �����߽��ϴ�.");
			break;
		case 2:
			printf("� ����? (A������ 1, B������ 2): ");
			scanf("%d", &ptr);
			if (Pop(&s, &x, ptr) == -1)
				puts("\aǪ�ÿ� �����߽��ϴ�.");
			else
				printf("�˵����ʹ� %d�Դϴ�.\n", x);
			break;

		case 3:
			printf("� ����? (A������ 1, B������ 2): ");
			scanf("%d", &ptr);
			if (Peek(&s, &x, ptr) == -1)
				puts("\a��ũ�� �����߽��ϴ�.");
			else
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			break;
		case 4:
			printf("� ����? (A������ 1, B������ 2): ");
			scanf("%d", &ptr);
			Print(&s,ptr);
			break;
		case 5:
			printf("�˻��� ������: ");
			scanf("%d", &x);
			index=Search(&s, x, stack);
			if (index == -1)
				puts("\a�˻��� �����߽��ϴ�.");
			else
				printf("�ش� �����ʹ� %c������ %d��° �ε����� �ֽ��ϴ�.\n", stack==1? 'A' : 'B', index);
			break;
		case 6:
			puts("������ û���մϴ�.");
			Clear(&s);
			break;
		}
	}
	Terminate(&s);

	//int temp;
	//scanf("%d", &temp);
	return 0;
}