#include <stdio.h>

int findIndexBinary(int a[], int len, int key);
void drawtable(int pl, int pr, int pc);
void printarray(int a[], int n);

int main() {
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	int size_a = sizeof(a) / sizeof(a[0]);

	puts("   |  0  1  2  3  4  5  6  7  8");
	puts("---+------------------------------");

	int k = 3; // 찾으려는 숫자
	int result = findIndexBinary(a, size_a, k);
	putchar('\n');
	if (result == -1)
		printf("검색에 실패했습니다,\n");
	else
		printf("%d는 x[%d]에 있습니다.", k, result);

	return 0;
}

int findIndexBinary(int a[], int len, int key) {
	int pl = 0;
	int pr = len - 1;
	int pc;
	do {
		pc = (pl + pr) / 2;
		drawtable(pl, pr, pc);
		printf("%3d|",a[pc]);
		printarray(a, len);
		if (a[pc] == key) return pc;
		else if (a[pc] < key) pl = pc + 1;
		else pr = pc - 1;
	} while (pl <= pr);
	return -1;
}

void drawtable(int pl, int pr, int pc) {
	printf("   |");
	for (int i = 0; i < pl; i++)
		printf("   ");
	printf("<-");
	for (int i = 0; i < pc - pl; i++)
		printf("   ");
	printf("+");
	for (int i = 0; i < pr - pc; i++)
		printf("   ");
	printf("->");
	putchar('\n');
}

void printarray(int a[], int n){
	for (int i = 0; i < n; i++)
		printf("%3d",a[i]);
	putchar('\n');
}
