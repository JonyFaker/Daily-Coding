#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

//采用按层遍历的方式
bool checkComplete(TreeNode* root)
{
    if(!root)
        return true;
    queue<TreeNode* > que;
    que.push(root);
    TreeNode* now = NULL;
    while(!que.empty()){
        now = que.front();
        que.pop();
        if(now->right && !now->left)
            return false;
        if(now->left)
            que.push(now->left);
        if(now->right)
            que.push(now->right);
        if(!now->left || !now->right)   //当前节点并不是左右孩子都有，则直接考察之后的节点是否均是叶节点
            break;
    }
    while(!que.empty()){
        now = que.front();
        que.pop();
        if(now->left || now->right)
            return false;
    }
    return true;
}


int main(int argc, char const *argv[])
{
    return 0;
}