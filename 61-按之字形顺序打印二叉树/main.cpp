#include<iostream>
#include<queue>
using namespace std;

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

//【我的一刷】
//感觉这题本质上是一个层序遍历
//先写一个层序遍历
//在层序遍历的基础上修改，加上奇偶改变方向
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        //安全性检查
        vector<vector<int>> result;    //保持返回结果
        if( pRoot == NULL ){
            return result;
        }

        queue<TreeNode*> q;     //层序遍历的辅助队列
        q.push(pRoot);
        bool even = false;
        while( !q.empty() ){
            vector<int> vec;
            const int size = q.size();
            for(int i=0; i<size; ++i){  //利用for循环把当前队列q中的元素取出来
                TreeNode* tmp = q.front();
                q.pop();
                if(!even)
                    vec.push_back(tmp->val);
                else
                    vec.insert(vec.begin(), tmp->val);

                if(tmp->left != NULL)
                    q.push(tmp->left);
                if(tmp->right != NULL)
                    q.push(tmp->right);
            }
            

            result.push_back(vec);
            even = !even;

        }
        return result;
    }
    
};

//【剑指offer】暂未通过
//在打印某一行的结点时，把下一层的子结点保存到相应的栈里
//如果当前打印的是奇数层，则先保存左子结点再保存右子结点到第一个栈里
//如果当前打印的是偶数层，则先保存到右子结点再保存左子结点到第二个栈里
//这里两个栈是必须的
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> result;    //保持返回结果
        if( pRoot == NULL ){
            return result;
        }

        stack<TreeNode*> levels[2];
        int current = 0;
        int next = 1;

        levels[current].push(pRoot);
        while( !levels[0].empty() || !levels[1].empty() ){
            TreeNode* pNode = levels[current].top();
            levels[current].pop();

            vector<int> vec;
            vec.push_back(pNode->val);

            if( current == 0 ){
                if( pNode->left != NULL )
                    levels[next].push(pNode->left);
                if( pNode->right != NULL )
                    levels[next].push(pNode->right);
            }else{
                if( pNode->right != NULL )
                    levels[next].push(pNode->right);
                if( pNode->left != NULL )
                    levels[next].push(pNode->left);
            }

            if( levels[current].empty() ){
                current = 1 - current;
                next = 1 - next;
            }
            result.push_back(vec);
        }

        return result;
    }
    
};