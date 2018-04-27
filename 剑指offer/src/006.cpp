
/*
重建二叉树
输入前序遍历和中序遍历的结果(无重复)，重建此二叉树
preorder:{1,2,4,7,3,5,6,8}
inorder:{4,7,2,1,5,3,8,6}
*/

#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

struct BinaryTreeNode 
{
    int                    m_nValue; 
    BinaryTreeNode*        m_pLeft;  
    BinaryTreeNode*        m_pRight; 
    //parent, for GetNextNode()
    BinaryTreeNode*		   m_pParent;
};

class BinaryTree
{
public:
	BinaryTree(int value) : treeNode->m_nValue(value), treeNode->m_pLeft(NULL), treeNode->m_pRight(NULL){}
	~BinaryTree();

	//给定前序 中序结果重建二叉树
	BinaryTreeNode* ConstructTree(int* preorder, int* inorder, int length)
	{
		if (preorder == nullptr || inorder == nullptr || length <= 0)
			return nullptr;

		return ConstrucIpl(preorder, preorder+length-1, inorder, inorder+length-1);
	}

	BinaryTreeNode* GetNextNode(BinaryTreeNode* pNode)
	{
		if (pNode == nullptr)
			return nullptr;

		BinaryTreeNode* pNext = nullptr;

		//分三种情况中序遍历搜索下一个节点
		//1.如果这个节点有右子树，那么他的下一个节点就是他的右子树中的最左的节点
		if (pNode->m_pRight != nullptr)
		{
			BinaryTreeNode* pRight = pNode->m_pRight;
			while(pRight->m_pLeft ！= nullptr)
			{
				pRight = pRight->m_pLeft;
			}
			pNext = pRight;
		}
		//2.如果如果这个节点没有右子树，它还是父节点的右子节点，在需要沿着父节点的指针一直向上遍历，直到
		//找到一个是它父节点的左子节点的节点。则该父节点即为我们需要找的节点
		else if(pNode->m_pParent != nullptr)
		{
			BinaryTreeNode* pCurrent = pNode;
			BinaryTreeNode* pPraent = pCurrent->m_pParent;
			while(pPraent != nullptr && pCurrent == m_pParent->m_pRight)
			{
				pCurrent = pPraent;
				pPraent = pCurrent->m_pParent;
			}
			//3.如果这个节点没有右子树，如果节点是它父节点的左子节点，则他的下一个节点即它的父节点
			pNext = pPraent;
		}

		retun pNext;
	}

// private:
// 	BinaryTreeNode* treeNode;

	BinaryTreeNode* ConstrucIpl(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
	{
		//前序遍历中找到的第一个数字就是跟节点的值
		int rootValue = startInorder[0];
		BinaryTreeNode* root = new BinaryTreeNode();
		root->m_nValue = rootValue;
		root->m_pLeft = root->m_pRight = nullptr;

		// 只包含一个节点
		if (startPreorder == endPreorder)
		{
			if (startInorder == endInorder && *startPreorder == *startInorder)
				return root;
			else
				throw std::exception("invalid input!");
		}

		//在中序遍历中找到根节点的值
		int* rootInorder = startInorder;
		while(rootInorder < endInorder && *rootInorder != rootValue)
			++rootInorder;

		if (rootInorder == endInorder && *rootInorder != rootValue)
			throw std::exception("invalid input!");

		int leftLegth = rootInorder - startInorder;
		int* leftPreorderEnd = startPreorder + leftLegth; //前序遍历root后几个是左子树的
		//构建左子树
		if (leftLegth > 0)
		{
			root->m_pLeft = ConstrucIpl(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder-1);
		}
		//构建右子树
		if (leftLegth < endPreorder - startPreorder) //此处判断还有右子树
		{
			root->m_pRight = ConstrucIpl(leftPreorderEnd + 1, endPreorder, rootInorder, endInorder);
		}

		return root;

	}
};

int main(int argc, char const *argv[])
{
	BinaryTree* tree = new BinaryTree();
	return 0;
}