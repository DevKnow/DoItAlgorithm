#include <stdio.h>

int bin_search2(int a[], int len, int key);
void printarray(int a[], int n);

int main() {
	int a[] = { 1,3,5,7,7,7,7,8,8,9,9 };
	int size_a = sizeof(a) / sizeof(a[0]);

	puts("   |  0  1  2  3  4  5  6  7  8  9  10");
	puts("---+-------------------------------------");

	int k = 7; // 찾으려는 숫자
	int result = bin_search2(a, size_a, k);
	putchar('\n');
	if (result == -1)
		printf("검색에 실패했습니다,\n");
	else
		printf("%d는 x[%d]에 있습니다.", k, result);

	return 0;
}

int bin_search2(int a[], int len, int key) {
	int pl = 0;
	int pr = len - 1;
	int pc;
	printarray(a, len);
	do {
		pc = (pl + pr) / 2;
		if (a[pc] == key) {
			for (int i = pc; a[i] == key; i--)
				pc--;
			return pc+1;
		}
		else if (a[pc] < key) pl = pc + 1;
		else pr = pc - 1;
	} while (pl <= pr);
	return -1;
}

void printarray(int a[], int n) {
	printf("   |");
	for (int i = 0; i < n; i++)
		printf("%3d", a[i]);
	putchar('\n');
}
