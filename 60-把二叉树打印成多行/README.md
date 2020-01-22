# 60-把二叉树打印成多行

牛客网链接：[60-把二叉树打印成多行](https://www.nowcoder.com/practice/445c44d982d04483b04a54f298796288?tpId=13&tqId=11213&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

题目描述

> 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。



## 1.一刷情况

**日期**：2020.01.22

**Code**：

```c++
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
```

**掌握情况**：会一半

**存在问题**：不知道如何将每一层的结点分开——用两个变量即可。变量toBePrinted记录当前层中未被打印的结点数，变量nextLevel是为了更新toBePrinted变量。





## 参考Code

无
