#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

//中序遍历
std::vector<int> findErrorNd(TreeNode* root)
{
    std::vector<int> res(2,0);  //保存两个错误的节点
    vector<vector<int> >t;  //分两种情况，一次降序和两次降序
    stack<TreeNode* > s;
    TreeNode* p = root;
    TreeNode* temp = NULL;
    int last=INT_MIN,now=0;
    while(!s.empty() || p != NULL){
        while(p != NULL){
            s.push(p);
            p = p->left;
        }
        temp = s.top();
        s.pop();
        now = temp->val;
        if(last > now){
            res[1] = last;
            res[0] = now;
            t.push_back(res);
        }
        last = now;
        p = temp->right;
    }
    //若只有一次降序，则第一个错误的节点为降序时较大的节点，第二个为较小的节点
    //否则，第一个为第一次降序较大的节点，第二个为第二次降序的较小节点
    if(t.size()!=1)
    {
        res[1]=t[0][1];
        res[0]=t[1][0];
    }
    return res;
}


int main(int argc, char const *argv[])
{
    return 0;
}