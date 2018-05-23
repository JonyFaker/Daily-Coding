#include <iostream>
#include <stack>
#include <vector>
#include <deque>
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

bool isPalin(ListNode* head)
{
	ListNode* p_head = head;
	stack<int> s;
	while(p_head != NULL){
		s.push(p_head->val);
		p_head = p_head->next;
	}
	p_head = head;
	while(p_head != NULL){
		int temp = s.top();
		if(temp != p_head->val){
			return false;
		}
		s.pop();
		p_head = p_head->next;
	}
	return true;
}


int main(int argc, char const *argv[])
{
	int a[8]={1,2,3,4,4,3,2,1};
	vector<int> arr(a,a+8);
	ListNode* head = buildList(arr);
	printList(head);
	cout<<"Palin ? : "<<isPalin(head)<<endl;
	return 0;
}