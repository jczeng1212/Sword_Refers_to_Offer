#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber){
        if(root == NULL){
            return result;
        }
        
        tmp.push_back(root->val);
        if((expectNumber - root->val ) == 0 && root->left == NULL && root->right == NULL){
            //到某叶结点且满足expectNumber值时，将一次得到序列放入result中
            result.push_back(tmp);
        }
        
        //遍历左子树
        FindPath(root->left, expectNumber - root->val);
        //遍历右子树
        FindPath(root->right, expectNumber - root->val);
        
        tmp.pop_back();
        return result;
    }
private:
    vector<vector<int> > result;
    vector<int> tmp;
};

int main(){
    TreeNode BTree[5] = {10, 5, 12, 4, 7};
    BTree[0].left = &BTree[1];
    BTree[0].right = &BTree[2];
    BTree[1].left = &BTree[3];
    BTree[1].right = &BTree[4];

    vector<vector<int> > res;
    Solution solution;
    res = solution.FindPath(BTree, 22);

    for (auto it = res.begin(); it != res.end(); ++it){
		for (int i = 0; i < (*it).size(); ++i)
			cout << (*it)[i] << " " ;

        cout << endl;
	}



    return 0;
}