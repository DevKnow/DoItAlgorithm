#ifndef ___INTSTACK
#define ___INTSTACK

typedef struct {
	int max; /* ���� �뷮 */
	int ptr; /* ���� ������ */
	int* stk; /* ������ ù ��ҿ� ���� ������ */
} IntStack;

/*--- ���� �ʱ�ȭ ---*/
int Initialize(IntStack* s, int max);

/*--- ���ÿ� �����͸� Ǫ�� ---*/
int Push(IntStack* s, int x);

/*--- ���ÿ��� �����͸� �� ---*/
int Pop(IntStack* s, int* x);

/*--- ���ÿ��� �����͸� ��ũ ---*/
int Peek(const IntStack* s, int* x);

/*--- ���� ���� ---*/
void Clear(IntStack* s);

/*--- ������ �ִ� �뷮 ---*/
int Capacity(const IntStack* s);

/*--- ������ ������ ���� ---*/
int Size(const IntStack* s);

/*--- ������ ����ֳ���? ---*/
bool IsEmpty(const IntStack* s);

/*--- ������ ���� á����? ---*/
int IsFull(const IntStack* s);

/*--- ���ÿ��� �˻� ---*/
int Search(const IntStack* s, int x);

/*--- ��� ������ ��� ---*/
void Print(const IntStack* s);

/*--- ���� ���� ---*/
void Terminate(IntStack* s);

#endif // !___INTSTACK