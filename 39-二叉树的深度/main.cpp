#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode( int x ):
        val(x), left(NULL), right(NULL){

        }
};

class Solution {

public:
    int TreeDepth(TreeNode* pRoot){
        

        if( pRoot == NULL ){
            return 0;
        }

        int depthLeft = TreeDepth(pRoot->left);
        int depthRight = TreeDepth(pRoot->right);

        return (depthLeft > depthRight)? depthLeft + 1 : depthRight + 1;


    }
    
    
};