#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int mdays[][12] = {
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

int isLeapYear(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

typedef struct {
	int y;
	int m;
	int d;
} Date;

Date DateOf(int y, int m, int d) {
	Date temp;
	temp.y = y;
	temp.m = m;
	temp.d = d;
	return temp;
}

Date After(Date x, int n) {
	Date temp = x;
	temp.d += n;
	if (temp.d > mdays[isLeapYear(temp.y)][temp.m - 1])
	{
		for (;;) {
			temp.d -= mdays[isLeapYear(temp.y)][temp.m - 1];
			if (temp.d == 0)
				temp.d++;
			if (++temp.m > 12) {
				temp.y++;
				temp.m = 1;
			}
			if (temp.d < mdays[isLeapYear(temp.y)][temp.m - 1]) break;
		}
	}
	return temp;
}

Date Before(Date x, int n) {
	Date temp = x;
	temp.d -= n;

	if (temp.d<=0)
	{
		for (;;) {
			temp.d += mdays[isLeapYear(temp.y)][temp.m - 1];
			if (temp.d == 0)
				temp.d = mdays[isLeapYear(temp.y)][temp.m - 1];
			if (--temp.m <= 0) {
				temp.y--;
				temp.m = 12;
			}
			if (temp.d > 0) break;
		}
	}
	
	return temp;
}

int main() {
	int year, month, day, menu, days, exit;
	while (1) {

		printf("��: "); scanf("%d", &year);
		printf("��: "); scanf("%d", &month);
		printf("��: "); scanf("%d", &day);
		Date date = DateOf(year, month, day);
		
		printf("[1] After\n[2] Before\n\n����: "); scanf("%d", &menu);

		switch (menu) {
		case 1:
			printf("��ĥ ��?: "); scanf("%d", &days);
			Date tempA = After(date, days);
			printf("���: %d�� %d�� %d��\n", tempA.y, tempA.m, tempA.d);
			break;
		case 2:
			printf("��ĥ ��?: "); scanf("%d", &days);
			Date tempB = Before(date, days);
			printf("���: %d�� %d�� %d��\n", tempB.y, tempB.m, tempB.d);
			break;
		default:
			printf("�߸��� �����Դϴ�.\n");
			break;
		}

		printf("����Ͻðڽ��ϱ�?(Y:1, N:2):"); scanf("%d", &exit);
		if (exit == 2) return 0;
	}

	return 0;
}