#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStack.h"

int main() {
	IntStack s;
	if (Initialize(&s, 10) == -1) {
		puts("���� ������ �����߽��ϴ�.");
		return 0;
	}

	while (1) {
		int menu, x, result, stackName;
		printf("���� �����ͼ�: %d / %d\n", Size(&s, STACK_A)+ Size(&s, STACK_B), Capacity(&s));
		printf("(1)Ǫ�� (2)�� (3)��ũ (4)��� (5)�˻� (6)�ʱ�ȭ (0)����: "); scanf("%d", &menu);


		if (menu == 0) break;
		switch (menu) {
		case 1:
			printf("Ǫ���� ����(A�� 1 B�� 2): "); scanf("%d", &stackName);
			printf("Ǫ���� ������: "); scanf("%d", &x);
			if (Push(&s, x, stackName) == -1)
				puts("\a����: Ǫ�ÿ� �����߽��ϴ�.");
			break;
		case 2:
			printf("���� ����(A�� 1 B�� 2): "); scanf("%d", &stackName);
			if (Pop(&s, &x, stackName) == -1)
				puts("\a����: �˿� �����߽��ϴ�.");
			else
				printf("�� �����ʹ� %d�Դϴ�.\n", x);
			break;
		case 3:
			printf("��ũ�� ����(A�� 1 B�� 2): "); scanf("%d", &stackName);
			if (Peek(&s, &x, stackName) == -1)
				puts("\a����: ��ũ�� �����߽��ϴ�.");
			else
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			break;
		case 4:
			Print(&s);
			break;
		case 5:
			printf("�˻��� ������: "); scanf("%d", &x);
			result = Search(&s, x, &stackName);
			if (result == -1)
				puts("\a����: �˻��� �����߽��ϴ�.");
			else
				printf("%d�� %d��°(%c����)�� �ֽ��ϴ�.\n", x, result, stackName == 1 ? 'A' : 'B');
			break;
		case 6:
			Clear(&s);
			break;
		}
	}
	Terminate(&s);

	return 0;
}