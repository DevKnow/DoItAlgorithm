#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int mdays[][12]{
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

int isleap(int y) {
	return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

typedef struct {
	int year;
	int month;
	int date;
} Date;

Date DateOf(int y, int m, int d);
Date After(Date x, int n);
Date Before(Date x, int n);

int main() {
	int y, m, d;
	printf("기준년: "); scanf("%d", &y);
	printf("기준월: "); scanf("%d", &m);
	printf("기준일: "); scanf("%d", &d);
	Date date = DateOf(y, m, d);

	int daysafter;
	printf("며칠 뒤 날짜를 보고 싶은가요?: "); scanf("%d", &daysafter);
	Date after = After(date, daysafter);
	printf("%d년 %d월 %d일입니다.\n", after.year, after.month, after.date);

	int daysbefore;
	printf("며칠 전 날짜를 보고 싶은가요?: "); scanf("%d", &daysbefore);
	Date before = Before(date, daysbefore);
	printf("%d년 %d월 %d일입니다.\n", before.year, before.month, before.date);

	return 0;
}

Date DateOf(int y, int m, int d) {
	Date temp;
	temp.year = y;
	temp.month = m;
	temp.date = d;
	return temp;
}

Date After(const Date x, int n) {
	Date after = x;
	int sumdays = after.date + n;
	if (sumdays <= mdays[isleap(x.year)][x.month - 1])
		after.date = sumdays;
	else {
		while (true) {
			int daysinMonth = mdays[isleap(after.year)][after.month - 1];
			if (sumdays / daysinMonth == 0) {
				after.date = sumdays;
				break;
			}
			sumdays -= daysinMonth;
			if (++after.month > 12) {
				after.month = 1;
				after.year++;
			}
		}
	}
	return after;
}

Date Before(Date x, int n) {
	Date before = x;
	int mindays = n - before.date;
	if (mindays < 0)
		before.date = before.date - n;
	else {
		while (true) {
			int daysinMonth = mdays[isleap(before.year)][before.month-- - 1];
			if (mindays / daysinMonth == 0) {
				before.date = daysinMonth - mindays+1;
				break;
			}
			mindays -= daysinMonth;
			if (before.month < 1) {
				before.month = 12;
				before.year--;
			}
		}
	}
	return before;
}
