#include <iostream>
#include <vector>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};


RandomListNode* clone(RandomListNode* pHead)
{
	if(!pHead)
        return pHead;
    //第一次遍历
    RandomListNode *p=pHead,*temp=NULL,*New=NULL;
    while(p){
        temp = p->next;
        New = new RandomListNode(p->label);
        New->next = p->next;
        p->next = New;
        p = temp;
    }
    //第二次遍历
    p = pHead, New = p->next;
    while(p){
        if(p->random)
            New->random = p->random->next;
        p = New->next;
        if(p)
            New = p->next;
    }
    //分离
    p = pHead, New = p->next;
    RandomListNode* NHead=New;
    while(New->next){
        temp = New->next;
        p->next = New->next;
        New->next = temp->next;
        p = temp;
        New = p->next;
    }
    p->next = NULL;
    return NHead;
}



int main(int argc, char const *argv[])
{
	return 0;
}