#include <stdio.h>
#include "IntStack.h"

// 정답으로 제공된 부분
// 전혀 못 풀어서 나중에 다시 풀어봐야할 듯
void recur3(int n)
{
    int sw = 0;
    IntStack nstk, sstk;

    Initialize(&nstk, 100);
    Initialize(&sstk, 100);

    while (1) {
        if (n > 0) {
            Push(&nstk, n);
            Push(&sstk, sw);

            if (sw == 0)
                n = n - 1;
            else if (sw == 1) {
                n = n - 2;
                sw = 0;
            }
            continue;
        }
        do {
            Pop(&nstk, &n);
            Pop(&sstk, &sw);
            sw++;

            if (sw == 2) {
                printf("%d\n", n);
                if (IsEmpty(&nstk))
                    return;
            }
        } while (sw == 2);
    }

    Terminate(&nstk);
    Terminate(&sstk);
}


int main() {
	
	recur3(3);

	return 0;
}