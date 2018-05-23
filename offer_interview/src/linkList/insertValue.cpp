#include<iostream>
#include<vector>
using namespace std;


struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};


ListNode* inserValue(ListNode* head, int val)
{
	if(head == NULL)
	{
		ListNode* result = new ListNode(val);
		result->next = result;
		return result;
	}else
	{
		ListNode* c_node = new ListNode(val);
		ListNode* p_front = head;
		ListNode* p_next = head->next;
		bool flag = false;
		while(p_next != head)
		{
			if(c_node->val >= p_front->val && c_node->val <= p_next->val)
			{
				p_front->next = c_node;
				c_node->next = p_next;
				flag = true;
				return head;
			}
			p_front = p_front->next;
			p_next = p_next->next;
		}
		if(flag == false)
		{
			p_front->next = c_node;
			c_node->next = p_next;
		}
		return head;

	}
	
}


//构造循环链表
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
	p_current->next = p_head;
	return p_head;
}

//打印循环链表
void printList(ListNode* head)
{
	ListNode* p_head = head;
	cout<<p_head->val<<" ";
	ListNode* p_current = p_head->next;
	while(p_current != p_head){
		cout<<p_current->val<<" ";
		p_current = p_current->next;
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int a[7]={3,3,7,7,8,12,13};
	vector<int> arr(a,a+7);
	ListNode* head = buildList(arr);
	cout<<"before insert: ";
	printList(head);
	int val = 10; //插入后保持有序，循环链表
	ListNode* p_head = inserValue(head, val);
	cout<<"after insert: ";
	printList(p_head);
	return 0;
}