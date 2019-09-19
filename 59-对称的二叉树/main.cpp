#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):
        val(x), left(NULL), right(NULL){

        }
};

/*
    【此方法无法通过，有问题】
    判断根结点是否为空；
    判断根结点的左右孩子结点为空，即仅一个根结点的情况；
    后面再进行递归形式判断

*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot){
        if( pRoot == NULL ){
            return true;
        }

        TreeNode *pLeft = pRoot->left;
        TreeNode *pRight = pRoot->right;

        //考虑 子结点中，一个为空，一个不为空的情况。
        if( pLeft == NULL && pRight != NULL ){
            return false;
        }
        if( pLeft != NULL && pRight == NULL ){
            return false;
        }

        if( pLeft->val != pRight->val ){
            return false;
        }

        return isSymmetrical(pLeft) && isSymmetrical(pRight);
        
        
    }//

};


/*
    定义：对称的遍历算法。
    假定前序遍历为：根，左，右。则对称的遍历算法为：根，右，左。
    如果二叉树的前序遍历序列和对称前序遍历序列是一样的，那么二叉树就是对称的。
    另外，在遍历的过程中，要把结点的空指针也考虑进来（为了排除二叉树结点元素全部为同一元素的情况）。
*/
class Solution
{
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == NULL)
        {
            return true;   
        }
        return isSymmetricalRecursion(pRoot->left, pRoot->right);
    }

    bool isSymmetricalRecursion(TreeNode *pLeft, TreeNode *pRight)
    {
        if(pLeft == NULL && pRight == NULL)
        {
            return true;
        }
        
        if(pLeft == NULL || pRight == NULL)
        {
            return false;
        }
        
        if(pLeft->val != pRight->val)
        {
            return false;
        }

        //  左子树的左与右子树的右对称
        //  左子树的右与右子树的左对称
        return isSymmetricalRecursion(pLeft->left, pRight->right) 
            && isSymmetricalRecursion(pLeft->right, pRight->left);
    }
};
