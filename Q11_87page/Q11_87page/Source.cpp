#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* 각 달의 날 수 */
int mdays[][12]{
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

/* year년이 윤년인가? */
int isleap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int dayofyear(int y, int m, int d) {
	while (true) {
		if (--m == 0) break;
		d += mdays[isleap(y)][m-1];
	}
	return d;
}

int main() {
	int year, month, day;
	int retry;
	do {
		printf("년: "); scanf("%d", &year);
		printf("월: "); scanf("%d", &month);
		printf("일: "); scanf("%d", &day);
		printf("%d년의 %d일 째입니다.\n", year, dayofyear(year, month, day));
		printf("다시 할까요? (1 … 예/0 … 아니오): "); scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}