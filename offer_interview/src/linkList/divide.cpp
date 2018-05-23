#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};

void swap(ListNode* p1, ListNode* p2)
{
	int temp = p1->val;
	p1->val = p2->val;
	p2->val = temp;
}


//快速排序？？不是最优解 
//使用三个链表，小于，等于，大于的各生成一个链表，再连接起来
void divide(ListNode* head, int divide)
{
	ListNode* p_current = head;
	ListNode* p_lt = new ListNode(-999);
	ListNode* p1 = p_lt;
	ListNode* p_gt = new ListNode(999);
	ListNode* p2 = p_gt;
	while(p_current != NULL)
	{
		if(p_current->val <= divide)
		{
			p1->next = p_current;
			p1 = p1->next;
		}else
		{
			p2->next = p_current;
			p2 = p2->next;
		}
		p_current = p_current->next;
	}
	p1->next = p_gt->next;
	ListNode* p_head = p_lt->next;
	p_lt = NULL;
	head = p_head;
}


//构造单链表
ListNode* buildList(std::vector<int> v)
{
	ListNode* p_head = new ListNode(v[0]);
	ListNode* p_current = p_head;
	for (int i = 1; i < v.size(); ++i)
	{
		ListNode* temp = new ListNode(v[i]);
		p_current->next = temp;
		p_current = temp;
	}
	// p_current->next = p_head;
	return p_head;
}


//打印单链表
void printList(ListNode* head)
{
	ListNode* p_head = head;
	cout<<p_head->val<<" ";
	ListNode* p_current = p_head->next;
	while(p_current != NULL){
		cout<<p_current->val<<" ";
		p_current = p_current->next;
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int a[4]={1,4,2,5};
	vector<int> arr(a,a+4);
	int divide_num = 3;
	ListNode* head = buildList(arr);
	printList(head);
	divide(head, divide_num);
	printList(head);
	return 0;
}