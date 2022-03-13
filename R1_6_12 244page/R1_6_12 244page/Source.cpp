#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];
	int height, weight;
} Person;

int npcmp(const Person* a, const Person* b) {
	return strcmp(a->name, b->name);
}

int hpcmp(const Person* a, const Person* b) {
	return a->height < b->height ? -1 : a->height > b->height ? 1 : 0;
}

int wpcmp(const Person* a, const Person* b) {
	return a->weight < b->weight ? -1 : a->weight > b->weight ? 1 : 0;
}

void PrintPerson(const Person x[], int nx) {
	for (int i = 0; i < nx; i++)
		printf("%-10s %dcm %dkg\n", x[i].name, x[i].height, x[i].weight);
}

int main() {
	Person x[] = {
		{"sumi", 170, 52},
		{"yoobin", 180, 70},
		{"sohee", 172, 63},
		{"jina", 165, 50}
	};

	int nx = sizeof(x) / sizeof(x[0]);

	puts("정렬 전");
	PrintPerson(x, nx);

	puts("\n이름으로 정렬");
	qsort(x, nx, sizeof(Person), (int(*)(const void*, const void*))npcmp);
	PrintPerson(x, nx);

	puts("\n키로 정렬");
	qsort(x, nx, sizeof(Person), (int(*)(const void*, const void*))hpcmp);
	PrintPerson(x, nx);

	puts("\n몸무게로 정렬");
	qsort(x, nx, sizeof(Person), (int(*)(const void*, const void*))wpcmp);
	PrintPerson(x, nx);

	return 0;
}