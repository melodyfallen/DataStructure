// SingleLinkedList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#define MaxSize 100

typedef struct LNode
{
	int data;
	struct LNode *next;
}LinkNode;

void CreateListF(LinkNode *&L, int a[], int n);
void InitList(LinkNode *&L);
void DestroyList(LinkNode *&L);
void DispList(LinkNode *L);
bool ListEmpty(LinkNode *L);
bool GetElem(LinkNode *L, int i, int &e);
bool ListInsert(LinkNode *&L, int i, int e);
bool ListDelete(LinkNode *&L, int i, int &e);
int ListLength(LinkNode *L);
int LocateElem(LinkNode *L, int e);

int main()
{
	LinkNode *list;
	int LinkedlistLength; //变量，用户输入，要创建的顺序表的长度
	int linkedlist[MaxSize];  //数组，用户输入，要创建的顺序表的每一个元素的值
	int searchNum;  //变量，用户输入，想要查找的元素的编号
	int e = 0;  //变量，程序输出，编号为searchNum的元素的值
	int insertLocation;  //变量，用户输入，想要插入新元素在顺序表中的位置
	int insertValue;  //变量，用户输入，想要插入的新元素的值
	int delLocation;  //变量，用户输入，想要删除元素在顺序表中的位置
	int delValue = 0;  //变量，，想要删除元素的值

	InitList(list);

	//接受用户输入要创建的顺序表的长度和每个元素的内容
	printf("请输入您要创建的单链表的长度：\n");
	scanf_s("%d", &LinkedlistLength);
	printf("请输入您创建的单链表的每个元素值，每行一个：\n");
	for (int i = 0; i < LinkedlistLength; i++)
	{
		scanf_s("%d", &linkedlist[i]);
	}

	CreateListF(list, linkedlist, LinkedlistLength);
	//输出创建、初始化完成的顺序表
	printf("你创建的单链表是：");
	DispList(list);
	printf("该单链表是空表吗？%d\n", ListEmpty(list)); //判断该顺序表是否为空表并输出结果
	printf("该单链表的长度是：%d\n", ListLength(list)); //计算该顺序表的长度并输出结果
	//接收用户输入，并查找对应编号的元素
	printf("请输入你要查找的元素的编号：");
	scanf_s("%d", &searchNum);
	GetElem(list, searchNum, e);
	printf("你要查询的编号为%d的元素在单链表中的值是：%d\n", searchNum, e);
	//接收用户输入，并将输入的元素插入到顺序表对应的位置上
	printf("请输入你想要插入元素的位置：");
	scanf_s("%d", &insertLocation);
	printf("请输入你想要插入的新元素的值：");
	scanf_s("%d", &insertValue);
	if (ListInsert(list, insertLocation, insertValue)) {
		//如果元素插入成功则输出消息并显示插入后的新顺序表
		printf("元素插入成功！新单链表是：");
		DispList(list);
	}
	else {
		//如果元素插入失败则输出失败提示消息
		printf("元素插入失败！");
	}
	//接受用户输入，删除输入位置的元素
	printf("请输入你想要删除元素的位置：");
	scanf_s("%d", &delLocation);
	if (ListDelete(list, delLocation, delValue)) {
		//如果元素删除成功则输出消息并显示删除后的新顺序表
		printf("元素删除成功！新单链表是：");
		DispList(list);
	}
	else
	{
		//如果元素删除失败则输出失败提示消息
		printf("元素删除失败！");
	}
	//销毁顺序表并提示
	DestroyList(list);
	printf("单链表已销毁，程序运行结束！请按任意键退出。");
}
//头插法创建线单链表
void CreateListF(LinkNode *&L, int a[], int n) {
	LinkNode *s;
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}
//初始化线性表
void InitList(LinkNode *&L) {
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL;
}
//销毁线性表
void DestroyList(LinkNode *&L) {
	LinkNode *pre = L, *p = L->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}
//判断线性表是否为空表
bool ListEmpty(LinkNode *L) {
	return(L->next == NULL);
}
//求线性表的长度
int ListLength(LinkNode *L) {
	int n = 0;
	LinkNode *p = L;
	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}
	return(n);
}
//输出线性表
void DispList(LinkNode *L) {
	LinkNode *p = L->next;
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}
//求线性表中某个数据元素值
bool GetElem(LinkNode *L, int i, int &e) {
	int j = 0;
	LinkNode *p = L;
	if (i <= 0)
	{
		return false;
	}
	while (j < i && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		e = p->data;
		return true;
	}
}
//按元素值查找
int LocateElem(LinkNode *L, int e) {
	int i = 1;
	LinkNode *p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
	{
		return(0);
	}
	else
	{
		return(i);
	}
}
//插入数据元素
bool ListInsert(LinkNode *&L, int i, int e) {
	int j = 0;
	LinkNode *p = L, *s;
	if (i <= 0)
	{
		return false;
	}
	while (j < i-1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}
//删除数据元素
bool ListDelete(LinkNode *&L, int i, int &e) {
	int j = 0;
	LinkNode *p = L, *q;
	if (i <= 0)
	{
		return false;
	}
	while (j < i-1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		q = p->next;
		if (q == NULL)
		{
			return false;
		}
		e = q->data;
		p->next = q->next;
		free(q);
		return true;
	}
}