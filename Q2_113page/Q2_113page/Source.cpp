#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void makeTable(int n);
void spotOnIndex(int i);
int findIndex(int arr[], int n, int key);

int main() {
	srand(time(0));
	int num;
	printf("�迭�� �ε��� ����: "); scanf("%d", &num);
	int key;
	printf("ã������ Ű �ѹ�: "); scanf("%d", &key);

	int* a = (int*)malloc(sizeof(int) * num);

	for (int i = 0; i < num; i++)
		a[i] = rand() % 9;

	makeTable(num);
	int keyn=findIndex(a, num, key);
	if (keyn == -1)
		printf("�˻��� �����߽��ϴ�.\n");
	else
		printf("key�� %d ��° �ε����� �ֽ��ϴ�.", keyn + 1);


	return 0;
}

void makeTable(int n){
	printf("   |");
	for (int i = 0; i < n; i++)
		printf("%3d", i);
	printf("\n---+");
	for (int i = 0; i < n + 1; i++)
		printf("---");
	putchar('\n');
}

void spotOnIndex(int n){
	printf("   | ");
	for (int i = 0; i < n; i++)
		printf("   ");
	printf(" * ");
	putchar('\n');
}

void printfarr(int arr[], int n, int i) {
	printf(" %d | ", i);
	for (int k = 0; k < n; k++)
		printf("%2d ", arr[k]);
}

int findIndex(int arr[], int n, int key) {
	int i = 0;
	arr[n] = key;
	for (i = 0;; i++) {
		if (arr[i] == key) {
			if (i == n) {
				putchar('\n');
				break;
			}
			spotOnIndex(i);
			printfarr(arr, n, i);
			putchar('\n');
			break;
		}
		spotOnIndex(i);
		printfarr(arr, n, i);
		putchar('\n');
	}
	return i != n ? i : -1;
}
