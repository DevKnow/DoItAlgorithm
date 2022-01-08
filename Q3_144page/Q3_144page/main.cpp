#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Queue.h"

int main() {
	ArrayIntQueue queue;
	if (Init(&queue, 5) == -1) {
		printf("큐 생성에 실패했습니다.");
		return 0;
	}

	while (1) {
		int choice, data;
		printf("큐 데이터: %d/%d\n", Size(&queue), Capacity(&queue));
		printf("(1)인큐 (2)디큐 (3)출력 (0)프로그램 종료: ");
		scanf("%d", &choice);

		if (choice == 0) {
			puts("프로그램을 종료합니다.");
			break;
		}
		switch (choice) {
		case 1:
			printf("데이터: ");
			scanf("%d", &data);
			if (Enqueue(&queue, data) == -1)
				printf("\a인큐에 실패했습니다.\n");
			break;
		case 2:
			if (Dequeue(&queue, &data) == -1)
				printf("\a디큐에 실패했습니다.\n");
			else
				printf("디큐 결과: %d\n", data);
			break;
		case 3:
			PrintQueue(&queue);
			break;
		}
	}
	Terminate(&queue);

	return 0;
}