#include "pch.h"
#include <iostream>
constexpr auto MaxSize = 100;;

typedef struct
{
	int data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack *&s);
void DestroyStack(SqStack *&s);
bool StackEmpty(SqStack *s);
bool Push(SqStack *&s, int e);
bool Pop(SqStack *&s, int &e);
bool GetTop(SqStack *s, int &e);
bool symmetry(int str[]);

int main(void)
{
	int StackSize;
	int inElem;
	int outElem=0;
	int topElem;
	int stackElem[MaxSize];
	int symStack[MaxSize];
	SqStack *stack;

	InitStack(stack);

	printf("请输入要创建的顺序栈的长度：");
	scanf_s("%d", &StackSize);
	printf("请输入要放入该顺序栈的元素（每行一个）：\n");
	for (int i = 0; i < StackSize; i++)
	{
		scanf_s("%d", &inElem);
		symStack[i] = inElem;
		Push(stack, inElem);
	}
	symStack[StackSize] = '\0';
	printf("该顺序栈是空栈吗？%d\n", StackEmpty(stack));
	GetTop(stack, topElem);
	printf("该顺序栈的栈顶元素是：%d\n", topElem);
	printf("顺序栈出栈：\n");
	for (int i = 0; i < StackSize; i++)
	{
		Pop(stack, outElem);
		printf("%3d", outElem);
	}

	printf("\n此串是对称串吗？%d", symmetry(symStack));
	return 0;
}

//初始化栈
void InitStack(SqStack *&s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}
//销毁栈
void DestroyStack(SqStack *&s)
{
	free(s);
}
//判断栈是否为空
bool StackEmpty(SqStack *s)
{
	return(s->top == -1);
}
//进栈
bool Push(SqStack *&s, int e)
{
	if (s->top == MaxSize-1)
	{
		return false;
	}
	s->top++;
	s->data[s->top] = e;
	return true;
}
//出栈
bool Pop(SqStack *&s, int &e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}
//取栈顶元素
bool GetTop(SqStack *s, int &e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}
//判断是否为对称串
bool symmetry(int str[])
{
	int i; int e;
	SqStack *st;
	InitStack(st);
	for (i = 0; str[i]!='\0'; i++)
	{
		Push(st, str[i]);
	}
	for (i = 0; str[i]!='\0'; i++)
	{
		Pop(st, e);
		if (str[i]!=e)
		{
			DestroyStack(st);
			return false;
		}
	}
	DestroyStack(st);
	return true;
}