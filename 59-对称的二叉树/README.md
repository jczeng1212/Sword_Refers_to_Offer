# 59-对称的二叉树

牛客网链接：[59-对称的二叉树](https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=13&tqId=11211&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

题目描述

> 请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。



## 1.一刷情况

**日期**：2019.09.19

**Code**：

```c++
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
```

**掌握情况**：完全不会

**存在问题**：尝试用递归做，但是没有做出来。





## 参考Code

### Code1 

**日期**：2019.09.

**方法**：按照刷题基础的说明，简明扼要说明方法是什么，用了什么数据结构等等。

**具体思路**：见注释。

**Code**：

```c++
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
```

**存在问题**：不理解最后的isSymmetricalRecursion(pLeft->left, pRight->right) && isSymmetricalRecursion(pLeft->right, pRight->left)中的 pLeft->left, pRight->right 和 pLeft->right, pRight->left。

而且，我感觉实际的代码并不是按剑指Offer中给出的思路来实现的。