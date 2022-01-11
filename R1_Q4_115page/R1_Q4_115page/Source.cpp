#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int draw_bin_search(const int a[], int n, int key);
void printTable(int n);

int main() {
	int nx, ky, idx;
	puts("연습문제4");
	printf("요소 개수: "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);
	for (int i = 0; i < nx; i++) {
		printf("x[%d] = ", i); scanf("%d", &x[i]);
	}
	printf("찾으려는 값: "); scanf("%d", &ky);
	
	idx=draw_bin_search(x, nx, ky);

	if (idx == -1)
		puts("\n검색에 실패했습니다.");
	else
		printf("\n%d는 x[%d]에 있습니다.", idx);

	return 0;
}

int draw_bin_search(const int a[], int n, int key) {
	int pl = 0;
	int pr = n - 1;
	int pc;
	printTable(n);
	do {
		pc = (pl + pr) / 2;
		printf("   |");
		for (int i = 0; i < n; i++) {
			if (pl == i) printf(" <-");
			else if (pr == i) {
				printf("-> ");
				break;
			}
			else if (pc == i) printf(" + ");
			else printf("   ");
		}
		printf("\n%2d |", pc);
		for (int i = 0; i < n; i++)
			printf("%2d ", a[i]);
		printf("\n");
		if (a[pc] == key) return pc;
		else if (a[pc] < key) pl = pc + 1;
		else pr = pc - 1;
	} while (pl<=pr);

	return -1;
}

void printTable(int n) {
	printf("   |");
	for (int i = 0; i < n; i++)
		printf("%2d ", i);
	printf("\n---+");
	for (int i = 0; i < n; i++)
		printf("---");
	puts("");
}