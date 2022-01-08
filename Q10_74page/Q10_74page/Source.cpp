#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define swap(type,x,y) do{type t=x;x=y;y=t;}while(0)

void ary_copy(int a[], const int b[], int n);
void shuffle(int a[], int n);

int main() {
	srand(time(0));

	int num = rand()%10 + 5;
	int* a;
	int* b = (int*)calloc(num, sizeof(int));
	printf("%d개의 정수\n", num);
	if (b != NULL) {
		for (int i = 0; i < num; i++)
			b[i] = rand() % 10;
		for (int i = 0; i < num; i++)
			printf("%d ", b[i]);
	}
	putchar('\n');

	a = (int*)calloc(num, sizeof(b[0]));

	ary_copy(a, b, num);

	puts("a 배열의 정수");

	if (a != NULL) {
		for (int i = 0; i < num; i++)
			printf("%d ", a[i]);
	}

	puts("\n셔플 후 a배열의 정수");

	shuffle(a, num);

	if (a != NULL) {
		for (int i = 0; i < num; i++)
			printf("%d ", a[i]);
	}

	return 0;
}

void ary_copy(int a[], const int b[], int n) {
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}

void shuffle(int a[], int n) { // n은 배열의 요소 개수
	for (int i = 0; i < n; i++) {
		int temp = 0;
		do {
			temp = rand() % n;
		} while (i == temp);
		swap(int, a[i], a[temp]);
	}
}
