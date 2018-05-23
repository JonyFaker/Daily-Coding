#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};

//O(N)   O(K)
//突然想到，这里的数组可以使用栈来代替
void inverse(ListNode* head, int k)
{
	int* temp = new int[k];
	int count = 0;
	ListNode* p_head = head;
	ListNode* p_current = head;
	ListNode* p_head_part = head;	//k 区间内的部分的head指针
	while(p_current != NULL){
		temp[count] = p_current->val;
		count++;
		if(count%k == 0){
			ListNode* p_iter = p_head_part;
			for (int i = k-1; i >= 0; i--)
			{
				p_iter->val = temp[i];
				p_iter = p_iter->next;
			}
			count = 0;
			p_head_part = p_current->next;
		}

		p_current = p_current->next;
	}

	delete[] temp;
	temp = NULL;
}


//O(N)  O(1)
ListNode* inverse_plus(ListNode* head, int k)
{
		if(!head||k<2)
			return head;
		ListNode *p=head,*q=head,*LastTail=NULL;
		int i=1,count=0;
		while(q)
		{
			if(i==k)
			{
				if(!count)
					head=q;
				else
					(*LastTail).next=q;
				ListNode *temp1=(*q).next,*temp2=NULL;
				while(q!=p)
				{
					temp2=(*p).next;
					if((*q).next==temp1)
						LastTail=p;
					(*p).next=(*q).next;
					(*q).next=p;
					p=temp2;
				}
				p=q=temp1;
				i=1;
				count++;
			}
			if(q)
				q=(*q).next;
			i++;
		}
		return head;	
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
	int a[8]={1,2,3,4,5,6,7,8};
	vector<int> arr(a,a+8);
	ListNode* head = buildList(arr);
	printList(head);
	inverse(head, 3);
	printList(head);
	return 0;
}