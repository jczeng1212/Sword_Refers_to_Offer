#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode( int x ):
        val(x), left(NULL), right(NULL){

        }
};

/*
    本题的实质是层序遍历。
    层序遍历需要用到队列。
    将某一个结点的左右孩子入队列，然后将他们出队列，出队列时输出该结点，并将其孩子入队列，不断重复这一过程
*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if( root == NULL ){
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        while( !q.empty() ){
            TreeNode *temp = q.front();
            res.push_back(temp->val);

            if( temp->left ){
                q.push(temp->left);
            }
            if( temp->right ){
                q.push(temp->right);
            }

            q.pop();
        }

        return res;
    }
};