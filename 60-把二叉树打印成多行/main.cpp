/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

//此题很明显就是层序遍历

class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > result;
            if( pRoot == NULL ){
                return result;
            }

            queue<TreeNode*> q;
            q.push(pRoot);
            int nextLevel = 0;
            int toBePrinted = 1;
            vector<int> vec;
            while( !q.empty() ){
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node->val);
                //print(node->val);
                //这里如何将按照一行一行地把二叉树输出？
                //增加两个变量即可
                //【参考剑指offer】
                //变量nextLevel:下一层结点的数目
                //变量toBePrinted:当前层中还没有打印的结点数

                if( node->left != NULL ){
                    q.push(node->left);
                    ++nextLevel;
                }
                if( node->right != NULL ){
                    q.push(node->right);
                    ++nextLevel;
                }

                --toBePrinted;
                if( toBePrinted == 0 ){ //当前层已打印完毕
                    toBePrinted = nextLevel;
                    nextLevel = 0;

                    result.push_back(vec);
                    vec.clear();
                }
            }

            return result;

        }
    
};