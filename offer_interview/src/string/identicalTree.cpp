#include<iostream>
#include<string>
using namespace std;

//普通解法：二叉树遍历+字符匹配
//最优：二叉树序列化+KMP  O(M+N)

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int value) : val(value), left(NULL), right(NULL) {}
};


class identicalTree
{
public:
    identicalTree();
    ~identicalTree();

    bool checkIdetical(TreeNode* A, TreeNode* B){
        string s1 = toString(A);
        string s2 = toString(B);
        size_t found = s1.find(s2);
        if(found != string::npos)
            return true;
        else
            return false;
    }

    string toString(TreeNode* root){
        if(!root)
            return NULL;
        string res;
        Serialize(root, res);
        return res;
    }

    //二叉树的遍历
    void Serialize(TreeNode* root, string& res){
        if(!root){
            res += "#!";
            return;
        }
        res += IntergerToString((*roo).val, res);
        Serialize((*root).left, res);
        Serialize((*root).right, res);
    }
    
    string IntergerToString(int val){
        if(!m)
            return "0!";
        string res;
        std::vector<int > v;
        while(m){
            v.push_back(m%10);
            m = m/10;
        }
        for (const std::vector<int>::reverse_iterator riter = v.rbegin(); riter != v.rend(); riter++)
        {
            res.push_back(*riter+48);
        }
        res.push_back('!');
        return res;
    }

private:

};


int main(int argc, char const *argv[])
{
    return 0;
}