#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Shell(int a[], int n);
void Shellver2(int a[], int n);

int main() {
	int nx;
	puts("Q12");
	printf("요소개수: "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);
	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}
	Shell(x, nx);
	//Shellver2(x, nx);

	free(x);
	return 0;
}

void Shell(int a[], int n) {
	int i, j, h, change = 0;
	for (h = n / 2; h > 0; h /= 2)
		for (i = h; i < n; i++) {
			int temp = a[i];
			for (j = i - h; j >= 0 && a[j] > temp; j -= h) {
				change++;
				a[j + h] = a[j];
			}
			a[j + h] = temp;
		}
	printf("Shell() change: %d\n", change);
}

void Shellver2(int a[], int n) {
	int i, j, h, change=0;
	for (h = 1; h < n / 9; h = h * 3 + 1)
		;
	for (; h > 0; h /= 3) {
		for (i = h; i < n; i++) {
			int temp = a[i];
			for (j = i - h; j >= 0 && a[j] > temp; j -= h){
				a[j + h] = a[j];
				change++;
			}
			a[j + h] = temp;
		}
	}
	printf("Shellver2() change: %d\n", change);
}