#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Queue.h"

int main() {
	ArrayIntQueue queue;
	if (Init(&queue, 5) == -1) {
		printf("ť ������ �����߽��ϴ�.");
		return 0;
	}

	while (1) {
		int choice, data;
		printf("ť ������: %d/%d\n", Size(&queue), Capacity(&queue));
		printf("(1)��ť (2)��ť (3)��� (0)���α׷� ����: ");
		scanf("%d", &choice);

		if (choice == 0) {
			puts("���α׷��� �����մϴ�.");
			break;
		}
		switch (choice) {
		case 1:
			printf("������: ");
			scanf("%d", &data);
			if (Enqueue(&queue, data) == -1)
				printf("\a��ť�� �����߽��ϴ�.\n");
			break;
		case 2:
			if (Dequeue(&queue, &data) == -1)
				printf("\a��ť�� �����߽��ϴ�.\n");
			else
				printf("��ť ���: %d\n", data);
			break;
		case 3:
			PrintQueue(&queue);
			break;
		}
	}
	Terminate(&queue);

	return 0;
}