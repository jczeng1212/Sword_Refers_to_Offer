#include<iostream>
#include<algorithm>
using namespace std;


struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode( int x ):
        val(x), left(NULL), right(NULL){

        }
};


/*
平衡二叉树：树中的以任何结点为根的树都为平衡二叉树。
对树进行遍历，对每个结点做一次查询是否为平衡二叉树即可。
*/
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        

        if( pRoot->left ){
            IsBalanced_Solution( pRoot->left );
        }
        if( pRoot->right ){
            IsBalanced_Solution( pRoot->right );
        }
    }
};

//需要重复遍历结点多次，见剑指offer
class Solution1{
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if( pRoot == NULL ){
            return true;
        }

        int left = TreeDepth( pRoot->left );
        int right = TreeDepth( pRoot->right );

        int diff = left - right;

        if( diff > 1 || diff < -1 )
            return false;
        else
            return IsBalanced_Solution( pRoot->left ) && IsBalanced_Solution( pRoot->right );

    }

    int TreeDepth(TreeNode *pRoot){
        if( pRoot == NULL ){
            return 0;
        }

        int left = TreeDepth( pRoot->left );
        int right = TreeDepth( pRoot->right );

        return max(left, right) + 1;

    }
};

//每个结点仅遍历一次，见剑指offer



int main(){
    
    return 0;
}