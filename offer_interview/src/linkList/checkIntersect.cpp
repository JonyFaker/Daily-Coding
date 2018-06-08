#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//若用哈希表，需要额外空间复杂度，若不用哈希表，O(N+M), O(1)
bool checkIntersect(ListNode* headA, ListNode* headB)
{
    if(!headA||!headB)
            return false;
    int NumofA=0,NumofB=0,count=0;
    ListNode *p=headA;
    while(p)
    {
        NumofA++;
        p=(*p).next;
    }
    p=headB;
    while(p)
    {
        NumofB++;
        p=(*p).next;
    }
    ListNode *L=NULL,*S=NULL;
    if(NumofA>NumofB)
        L=headA,S=headB;
    else
        L=headB,S=headA;
    count=(NumofA>NumofB)?(NumofA-NumofB):(NumofB-NumofA);
    while(count--)
        L=(*L).next;
    while(L&&S){
        if(L == S)
            return true;
        L = L->next;
        S = S->next;
    }

    return false;
}


int main(int argc, char const *argv[])
{
    return 0;
}