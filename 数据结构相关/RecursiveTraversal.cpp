#include<iostream>
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

void LayerOrder( TreeNode *root ){
    if( root == NULL ){
        return NULL;
    }
    queue<TreeNode*> q;
    q.push(root);
    while( !q.empty() ){
        TreeNode* node = q.front();
        print(node->val);
        q.pop();
        if( node->left != NULL ){
            q.push(node->left);
        }
        if( node->right != NULL ){
            q.push(node->right);
        }
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