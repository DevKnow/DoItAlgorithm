#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "ArrayIntQueue.h"

int main() {
	ArrayIntQueue a;
	if (Initialize(&a, 10) == -1) {
		puts("ť ������ �����߽��ϴ�.");
		return -1;
	}

	int menu, x;
	while (1) {
		printf("���� ������: %d / %d\n", Size(&a), Capacity(&a));
		printf("(1)��ť (2)��ť (0)���α׷�����: "); scanf("%d", &menu);
		if (menu == 0) break;
		switch (menu)
		{
		case 1:
			printf("��ť�� ��: "); scanf("%d", &x);
			if (Enqueue(&a, x) == -1)
				puts("\a��ť�� �����߽��ϴ�.");
			break;
		case 2:
			if (Dequeue(&a, &x) == -1)
				puts("\a��ť�� �����߽��ϴ�.");
			else
				printf("��ť�� ��: %d\n", x);
			break;
		}
	}

	return 0;
}