#ifndef ___INTSTACK
#define ___INTSTACK

typedef struct {
	int max; /* 스택 용량 */
	int ptr_A; /* A스택 포인터 */
	int ptr_B; /* B스택 포인터 */
	int* stk; /* 스택의 첫 요소에 대한 포인터 */
} IntStack;

enum PTR {
	PTR_A = 1, PTR_B = 2
};

/*--- 스택 초기화 ---*/
int Initialize(IntStack* s, int max);

/*--- 스택에 데이터를 푸시 ---*/
int Push(IntStack* s, int x, int ptr);

/*--- 스택에서 데이터를 팝 ---*/
int Pop(IntStack* s, int* x, int ptr);

/*--- 스택에서 데이터를 피크 ---*/
int Peek(const IntStack* s, int* x, int ptr);

/*--- 스택 비우기 ---*/
void Clear(IntStack* s);

/*--- 스택의 최대 용량 ---*/
int Capacity(const IntStack* s);

/*--- 스택의 데이터 개수 ---*/
int Size(const IntStack* s, int ptr);

/*--- 스택이 비어있나요? ---*/
int IsEmpty(const IntStack* s, int ptr);

/*--- 스택이 가득 찼나요? ---*/
int IsFull(const IntStack* s);

/*--- 스택에서 검색 ---*/
int Search(const IntStack* s, int x, int& stack);

/*--- 모든 데이터 출력 ---*/
void Print(const IntStack* s, int ptr);

/*--- 스택 종료 ---*/
void Terminate(IntStack* s);

#endif // !___INTSTACK
