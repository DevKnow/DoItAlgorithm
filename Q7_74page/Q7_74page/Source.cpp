#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define swap(type, x, y) do{type t=x; x=y;y=t;}while(0)

int card_conv(unsigned x, int n, char d[]) {
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;
	
	for (int i = 0; x != 0;i++) {
		printf("%2d|", n);
		d[digits++] = dchar[x % n];
		printf("%6u �� %c\n", x, d[i]);
		x /= n;
		printf("--+------\n");
	}
	printf("  |     0\n");

	return digits;
}

int main() {
	int i;
	unsigned no; // ��ȯ��� ����
	int cd; // ��ȯ�Ϸ��� ����
	int dno; // ��ȯ �� �ڸ���
	char cno[512]; // ��ȯ �� ���� ���� �迭
	int retry; // �ٽ� ���� ����
	puts("10������ ��� ��ȯ�մϴ�.");
	do {
		printf("��ȯ�ϴ� ���� �ƴ� ����: ");
		scanf("%u", &no);
		do {
			printf("� ������ ��ȯ�ұ��? (2~36): ");
			scanf("%d", &cd);
		} while (cd < 2 || cd>36);
		
		dno=card_conv(no, cd, cno);

		printf("%d�����δ� ", cd);

		for (i = 0; i < dno; i++) // cno[dno]='\0'��
			printf("%c", cno[i]);

		puts("�Դϴ�");

		printf("�� �� �� �ұ��? (1...��/0...�ƴϿ�): ");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}