#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};

//O(1)，此种方法本质上是拷贝操作，如果数据结构复杂，将消耗大量时间拷贝；
//如果要删除的是最后一个节点，必须知道前一个指针的地址，不能直接将当前节点设为null，因为null是一个特定的区域, 
//即使当前节点为设为null，前一个节点也不会指向该设定的null
bool removeNode(ListNode* pNode)
{
	if((*pNode).next==NULL)
		return false;
	ListNode *p=(*pNode).next,*pre=pNode;
	while((*p).next!=NULL)
	{
		(*pre).val=(*p).val;
		pre=p;
		p=(*p).next;
	}
	(*pre).val=(*p).val;
	(*pre).next=NULL;
	delete p;
	p=NULL;
	return true;
}

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
	return p_head;
}

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
	return 0;
}