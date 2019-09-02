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

//前序遍历
void PreOrder( TreeNode *root ){
        if( root == NULL ){
            return;
        }

        cout << root->val << " ";
        if( root->left != NULL ){
            PreOrder(root->left);
        }
        if( root->right != NULL ){
            PreOrder(root->right);
        }
    }

int main(){
    TreeNode BTree[5] = {10, 5, 12, 4, 7};
    BTree[0].left = &BTree[1];
    BTree[0].right = &BTree[2];
    BTree[1].left = &BTree[3];
    BTree[1].right = &BTree[4];

    PreOrder(BTree);

    return 0;
}