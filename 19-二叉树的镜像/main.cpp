#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if( pRoot == NULL ){
            return;     //当函数返回为void，使用return结束语句
        }

        //这里不用判断是否为空就进行交换，是因为二叉树的一定要区分左右子树的特性
        TreeNode *temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        
        if( pRoot->left != NULL ){
            Mirror( pRoot->left );
        }
        if( pRoot->right != NULL ){
            Mirror( pRoot->right );
        }

    }
};



int main(){

    return 0;
}