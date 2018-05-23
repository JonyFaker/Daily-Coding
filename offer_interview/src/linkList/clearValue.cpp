#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};

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

void clearValue(ListNode* head, int val)
{
	while(head->val == val)
		head = head->next;
	ListNode* p_previous = head;
	ListNode* p_current = head->next;
	while(p_current){
		if(p_current->val == val){
			if(p_current->next == NULL){
				p_previous->next = NULL;
				break;
			}else{
				p_previous->next = p_current->next;
				p_current->next = NULL;
				p_current = p_previous->next;
			}
		}
		p_previous = p_previous->next;
		p_current = p_current->next;
	}
}


int main(int argc, char const *argv[])
{
	int a[8]={1,2,3,4,5,6,7,8};
	vector<int> arr(a,a+8);
	ListNode* head = buildList(arr);
	printList(head);
	clearValue(head, 2);
	printList(head);
	return 0;
}