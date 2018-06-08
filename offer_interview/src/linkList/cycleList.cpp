#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

//O(N)  O(N) 使用哈希表(略)，O(N)  O(1) 不使用哈希表
int isCycle(ListNode* head)
{
    if(!head)
        return -1;
    //第一轮，快指针一次2步，慢指针一次1步
    ListNode* p_slow, p_fast = head;
    while(p_fast != NULL){
        p_slow = p_slow->next;
        p_fast = p_fast->next->next;
        if(p_fast == NULL)
            return -1;
        if(p_slow == p_fast)
            break;
    }
    //第二轮，快指针回到头部，两个指针都一次走一步，直到相遇，即为第一个进入环的节点
    p_fast = head;
    while(p_fast != p_slow){
        p_slow = p_slow->next;
        p_fast = p_fast->next;
    }

    return p_fast->val;
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
    return 0;
}