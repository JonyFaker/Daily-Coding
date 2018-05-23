#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};


std::vector<int> getCommon(ListNode* headA, ListNode* headB)
{
	std::vector<int> res;
	while(headA != NULL && headB != NULL)
	{
		if(headA->val == headB->val){
			res.push_back(headA->val);
			headA = headA->next;
			headB = headB->next;
		}else if(headA->val < headB->val){
			headA = headA->next;
		}else{
			headB = headB->next;
		}
	}

	return res;
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
	int a[6]={1,1,2,4,5,8};
	vector<int> arr1(a,a+6);
	int b[8]={1,2,3,4,5,8,10,12};
	vector<int> arr2(b,b+8);
	ListNode* headA = buildList(arr1);
	ListNode* headB = buildList(arr2);
	std::vector<int> res = getCommon(headA, headB);
	cout<<"common part: ";
	for (auto i = res.begin(); i != res.end(); i++)
	{
		cout<<*i<<" ";
	}
	cout<<endl;
	return 0;
}