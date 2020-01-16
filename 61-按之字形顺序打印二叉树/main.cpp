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
        if( pRoot == NULL ){
            return NULL;
        }

        vector<vector<int> > result;    //保持返回结果
        int row = 0; //记录第几层数
        queue<TreeNode*> q;     //层序遍历的辅助队列
        TreeNode *node = pRoot;
        q.push(node);
        while( q.empty != true ){
            result[row].push_back(q.front());
            q.pop();

        }
        
    }
    
};

//【剑指offer】
//在打印某一行的结点时，把下一层的子结点保存到相应的栈里
//如果当前打印的是奇数层，则先保存左子结点再保存右子结点到第一个栈里
//如果当前打印的是偶数层，则先保存到右子结点再保存左子结点到第二个栈里
//这里两个栈是必须的
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        
    }
    
};