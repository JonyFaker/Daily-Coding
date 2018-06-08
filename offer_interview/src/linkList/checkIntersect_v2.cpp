#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//O(M+N)  O(1)  判断有环链表相交节点
ListNode* checkIntersect(ListNode* headA, ListNode* headB)
{
    if(!headA || !headB)
        return NULL;
    //1.先找到链表各自的入环节点
    //2.1 如果两个入环节点是同一个，则是相交的，那么第一个相交的节点一定在入环节点之前或者是入环节点
    //2.2 以入环节点为终止位置用无环链表判断相交的节点的方法
    
    //3. 两个入环节点不是同一个，则有两种情况，两个单独的环链表，或者共同的环，不同的入环节点
    // 从第一个入环节点往下走，如果在回到出发点之前没有遇到第二个入环点，则两个链表是不想交的，
    // 否则是相交的，返回任意一个入环点即可

}

int main(int argc, char const *argv[])
{
    return 0;
}