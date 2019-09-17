#include<iostream>
#include<algorithm>
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
    平衡二叉树要求：树的所有叶子结点深度之差小于等于1
    首先肯定是递归的思路。
    递归边界：结点为NULL时，返回。
    递归方程：求某一根结点的树的深度，就是求max(其两个子树的深度)+1。这样就把大问题化到小问题上了。
    到达叶结点，记录树的深度。主要是记录两个深度：一个是最小的深度，一个是最大的深度。
    比较这两个深度，差的绝对值超过1，就返回false，否则返回true。

    
*/
class Solution {
public:
    int maxDepth = 0;
    int minDepth = 0;
    int depth;
    

    bool IsBalanced_Solution(TreeNode* pRoot) {
        

        if( pRoot == NULL ){
            return true;
        }

        if( pRoot->left == NULL && pRoot->right == NULL ){
            depth++;    //到达叶结点，则深度加一
            if( depth > maxDepth ){
                maxDepth = depth;
            }
            if( depth < minDepth ){
                minDepth = depth;
            }

            if( (maxDepth - minDepth) > 1  ){
                return true;
            }
        }//if

        depth = 0;
        IsBalanced_Solution(pRoot->left);
        IsBalanced_Solution(pRoot->right);

        return false;

    }
};