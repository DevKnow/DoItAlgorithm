#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];
	int height;
	int weight;
} Person;

int npcmp(const Person* x, const Person* y) {
	return strcmp(x->name, y->name);
}

int main() {

	Person x[] = {
		{"�迵��", 179, 79},
		{"������", 172, 63},
		{"�̼���", 176, 52},
		{"������", 165, 51},
		{"������", 181, 73},
		{"ȫ����", 172, 84}
	};

	int nx = sizeof(x) / sizeof(x[0]);
	int retry;
	puts("�̸����� �˻�");
	do {
		Person temp, * p;
		printf("�̸�: "); scanf("%s", temp.name);
		p = (Person*)bsearch(&temp, x, nx, sizeof(Person), (int(*)(const void*, const void*))npcmp);
		if (p == NULL)
			puts("�˻� ����");
		else {
			puts("�˻� ����! �Ʒ� ��Ҹ� ã�ҽ��ϴ�.");
			printf("x[%d]: %s | %dcm | %dkg\n", (int)(p - x), p->name, p->height, p->weight);
		}
		printf("�ٽ� �˻��ұ��? (1)�� (2) �ƴϿ� : "); scanf("%d", &retry);
	} while (retry == 1);
	return 0;
}