#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntQueue.h"

int main() {
	IntQueue que;

	if (Initialize(&que, 12) == -1) {
		puts("ť ������ �����߽��ϴ�.");
		return -1;
	}

	int m, x, idx;
	while (1) {
		printf("���� ������ ��: %d / %d\n", Size(&que), Capacity(&que));
		printf("(1)��ť (2)��ť (3)��ũ (4)��� (5)�˻� (6)�ʱ�ȭ (0)����: "); scanf("%d", &m);

		if (m == 0) break;
		switch (m) {
		case 1:
			printf("��ť�� ��: "); scanf("%d", &x);
			if (Enque(&que, x) == -1)
				puts("\a��ť ����");
			break;
		case 2:
			if (Deque(&que, &x) == -1)
				puts("\a��ť ����");
			else
				printf("��ť ���: %d\n", x);
			break;
		case 3:
			if (Peek(&que, &x) == -1)
				puts("\a��ũ ����");
			else
				printf("��ũ ���: %d\n", x);
			break;
		case 4:
			Print(&que);
			break;
		case 5:
			printf("�˻��� ��: "); scanf("%d", &x);
			if (idx = Search(&que, x) == -1)
				puts("\a�˻� ����");
			else
				printf("%d�� %d��°�� �ֽ��ϴ�.\n", x, idx);
			break;
		case 6:
			Clear(&que);
			break;
		}
	}

	Terminate(&que);
	return 0;
}