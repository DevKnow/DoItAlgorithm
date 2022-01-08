#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define swap(type, x, y) do{type t=x; x=y;y=t;}while(0)

int card_conv(unsigned x, int n, char d[]) {
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;
	
	for (int i = 0; x != 0;i++) {
		printf("%2d|", n);
		d[digits++] = dchar[x % n];
		printf("%6u … %c\n", x, d[i]);
		x /= n;
		printf("--+------\n");
	}
	printf("  |     0\n");

	return digits;
}

int main() {
	int i;
	unsigned no; // 변환대상 숫자
	int cd; // 변환하려는 진수
	int dno; // 변환 후 자릿수
	char cno[512]; // 변환 후 문자 저장 배열
	int retry; // 다시 할지 말지
	puts("10진수를 기수 변환합니다.");
	do {
		printf("변환하는 음이 아닌 정수: ");
		scanf("%u", &no);
		do {
			printf("어떤 진수로 변환할까요? (2~36): ");
			scanf("%d", &cd);
		} while (cd < 2 || cd>36);
		
		dno=card_conv(no, cd, cno);

		printf("%d진수로는 ", cd);

		for (i = 0; i < dno; i++) // cno[dno]='\0'임
			printf("%c", cno[i]);

		puts("입니다");

		printf("한 번 더 할까요? (1...예/0...아니오): ");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}