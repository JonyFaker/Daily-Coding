#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};


void preOrderRecur(TreeNode* root, vector<int >& arr)
{
    if(root == NULL)
        return;
    arr.push_back(root->val);
    preOrderRecur(root->left, arr);
    preOrderRecur(root->right, arr);
}

void preOrder(TreeNode* root, std::vector<> arr;)
{
    stack<TreeNode*> s;
    TreeNode* p = root;
    while(!s.empty() || p != NULL){
        while(p != NULL){
            arr.push_back(p_>val);
            s.push(p);
            p = p->left;
        }
        if(!s.empty()){
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

void inOrderRecur(TreeNode* root, vector<int >& arr)
{
    if(root == NULL)
        return;
    inOrderRecur(root->left, arr);
    arr.push_back(root->val);
    inOrderRecur(root->right, arr);
}

void inOrder(TreeNode* root, std::vector<int>& arr)
{
    stack<TreeNode*> s;
    TreeNode* p = root;
    while(!s.empty() || p != NULL){
        while(p != NULL){
            s.push(p);
            p = p->left;
        }
        if(!s.empty()){
            p = s.top();
            arr.push_back(p->val);
            s.pop();
            p = p->right;
        }
    }
}

void postOrderRecur(TreeNode* root, vector<int >& arr)
{
    if(root == NULL)
        return;
    postOrderRecur(root->left);
    postOrderRecur(root->right);
    arr.push_back(root->val);
}

void postOrder(TreeNode* root, std::vector<int > arr)
{
    stack<TreeNode* > s1;
    stack<TreeNode* > s2;
    TreeNode* p = root;
    while(p != NULL || !s1.empty()){
        s1.push(p);
        while(!s1.empty()){
            TreeNode* temp = s1.top();
            p = temp;
            s1.pop();
            s2.push(temp);
            if(p->left)
                s1.push(p->left);
            if(p->right)
                s1.push(p->right);
        }
    }
    while(!s2.empty()){
        arr.push_back(s2.top()->val);
        s2.pop();
    }
}

int main(int argc, char const *argv[])
{
    return 0;
}