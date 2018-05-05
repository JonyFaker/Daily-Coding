/*

链表的基础操作
从头到尾打印链表
反转链表

*/

#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>
using namespace std;

struct ListNode
{
    int       m_nValue;
    ListNode* m_pNext;
};

ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = NULL;

    return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == NULL)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    pCurrent->m_pNext = pNext;
}

void PrintListNode(ListNode* pNode)
{ 
    if(pNode == NULL)
    {
        printf("The node is NULL\n");
    }
    else
    {
        printf("The key in node is %d.\n", pNode->m_nValue);
    }
}

void PrintList(ListNode* pHead)
{
    printf("PrintList starts.\n");
    
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        printf("%d\t", pNode->m_nValue);
        pNode = pNode->m_pNext;
    }

    printf("\nPrintList ends.\n");
}

void DestroyList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}

void AddToTail(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode();
    pNew->m_nValue = value;
    pNew->m_pNext = NULL;

    if(*pHead == NULL)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != NULL)
            pNode = pNode->m_pNext;

        pNode->m_pNext = pNew;
    }
}

void RemoveNode(ListNode** pHead, int value)
{
    if(pHead == NULL || *pHead == NULL)
        return;

    ListNode* pToBeDeleted = NULL;
    if((*pHead)->m_nValue == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value)
            pNode = pNode->m_pNext;

        if(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value)
        {
            pToBeDeleted = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
    }

    if(pToBeDeleted != NULL)
    {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}

void PrintListReversingly_Iteratively(ListNode* pHead)
{
    std::stack<ListNode*> nodes;

    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while(!nodes.empty())
    {
        pNode = nodes.top();
        printf("%d\t", pNode->m_nValue);
        nodes.pop();
    }
}

//与使用栈的思想一样，递归操作本质上就是一个栈结构，所以每次访问到一个节点的时候，
//先访问他的后面的节点，再输出自身
void PrintListReversingly_Recursively(ListNode* pHead)
{
    if(pHead != NULL)
    {
        if (pHead->m_pNext != NULL)
        {
            PrintListReversingly_Recursively(pHead->m_pNext);
        }
 
        printf("%d\t", pHead->m_nValue);
    }
}


//输入一个链表，反转链表后，输出链表的所有元素
//在牛客的测试中，输入为{} 这段程序输出为{1,}，没想通为什么
ListNode* ReverseList(ListNode* pHead) {

	if(pHead == nullptr)
    {
        return nullptr;
    }

    std::stack<ListNode*> nodes;
        
    ListNode* pCurrent = pHead;
    while(pCurrent != nullptr)
    {
        nodes.push(pCurrent);
        pCurrent = pCurrent->m_pNext;
    }

    ListNode* phead_r = nodes.top();
    printf("{%d,", phead_r->m_nValue);
    ListNode** pphead_r = &phead_r;

    nodes.pop();
    while(!nodes.empty())
    {
        pCurrent = nodes.top();
        phead_r->m_pNext = pCurrent;
        pCurrent->m_pNext = nullptr;
        phead_r = pCurrent;
        if (nodes.size() == 1)
        	printf("%d", pCurrent->m_nValue);
        else
        	printf("%d,", pCurrent->m_nValue);

        // printf("%d\t", pCurrent->m_nValue);
        nodes.pop();
    }
    printf("}\n");

    return *pphead_r;
}

int main(int argc, char const *argv[])
{
	//1.创建链表节点
	ListNode* p1 = CreateListNode(1);
	ListNode* p2 = CreateListNode(2);
	ListNode* p3 = CreateListNode(3);
	ListNode* p4 = CreateListNode(4);
	ListNode* p5 = CreateListNode(5);

	//2.连接这些节点
	ConnectListNodes(p1, p2);
	ConnectListNodes(p2, p3);
	ConnectListNodes(p3, p4);
	ConnectListNodes(p4, p5);

	//3.反转链表
	ListNode* phead_r = ReverseList(p1);

	return 0;
}




