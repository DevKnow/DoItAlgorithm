#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];
	int height, weight;
} Person;

int npcmp(const Person* x, const Person* y) {
	return strcmp(x->name, y->name);
}

int hpcmp(const Person* x, const Person* y) {
	return x->height < y->height ? -1 : x->height>y->height ? 1 : 0;
}

int wpcmp(const Person* x, const Person* y) {
	return x->weight < y->weight ? -1 : x->weight>y->weight ? 1 : 0;
}

void print_person(const Person x[], int no) {
	for (int i = 0; i < no; i++) {
		printf("%-10s %dcm, %dkg\n", x[i].name, x[i].height, x[i].weight);
	}
}

int main() {
	Person x[] = {
		{"Sunmi", 170, 52},
		{"Yoomi", 180, 70},
		{"Sohee", 172, 63},
		{"Jinha", 165, 50}
	};

	int nx = sizeof(x) / sizeof(x[0]);

	puts("정렬 전");
	print_person(x, nx);

	qsort(x, nx, sizeof(Person), (int(*)(const void*, const void*))npcmp);
	puts("이름 오름차순 정렬 후");
	print_person(x, nx);

	qsort(x, nx, sizeof(Person), (int(*)(const void*, const void*))hpcmp);
	puts("키 오름차순 정렬 후");
	print_person(x, nx);

	qsort(x, nx, sizeof(Person), (int(*)(const void*, const void*))wpcmp);
	puts("몸무게 오름차순 정렬 후");
	print_person(x, nx);

	return 0;
}