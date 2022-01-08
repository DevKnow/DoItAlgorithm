#ifndef ___INTSTACK
#define ___INTSTACK

typedef struct {
	int max; /* ���� �뷮 */
	int ptr_A; /* A���� ������ */
	int ptr_B; /* B���� ������ */
	int* stk; /* ������ ù ��ҿ� ���� ������ */
} IntStack;

enum PTR {
	PTR_A = 1, PTR_B = 2
};

/*--- ���� �ʱ�ȭ ---*/
int Initialize(IntStack* s, int max);

/*--- ���ÿ� �����͸� Ǫ�� ---*/
int Push(IntStack* s, int x, int ptr);

/*--- ���ÿ��� �����͸� �� ---*/
int Pop(IntStack* s, int* x, int ptr);

/*--- ���ÿ��� �����͸� ��ũ ---*/
int Peek(const IntStack* s, int* x, int ptr);

/*--- ���� ���� ---*/
void Clear(IntStack* s);

/*--- ������ �ִ� �뷮 ---*/
int Capacity(const IntStack* s);

/*--- ������ ������ ���� ---*/
int Size(const IntStack* s, int ptr);

/*--- ������ ����ֳ���? ---*/
int IsEmpty(const IntStack* s, int ptr);

/*--- ������ ���� á����? ---*/
int IsFull(const IntStack* s);

/*--- ���ÿ��� �˻� ---*/
int Search(const IntStack* s, int x, int& stack);

/*--- ��� ������ ��� ---*/
void Print(const IntStack* s, int ptr);

/*--- ���� ���� ---*/
void Terminate(IntStack* s);

#endif // !___INTSTACK
