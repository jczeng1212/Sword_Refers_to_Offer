# 01-题目

牛客网链接：[61-按之字形顺序打印二叉树](https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=13&tqId=11212&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

题目描述

> 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。



## 1.一刷情况

**日期**：2020.01.19

**Code**：

```c++
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
        while( !q.empty() ){
            result[row].push_back(q.front());
            q.pop();

        }
        
    }
    
};
```

**掌握情况**：会一半

**存在问题**：





## 参考Code

### Code1 来自牛客网

**日期**：2020.01.19

**方法**：层次遍历加上判断奇偶改变方向

**具体思路**：数据结构：一个层序遍历的队列q，一个vector vec

**Code**：

```c++
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        //安全性检查
        vector<vector<int> > result;    //保持返回结果
        if( pRoot == NULL ){
            return result;
        }
        
        /*注意下面的写法就是错误的：
        if( pRoot == NULL ){
            return NULL; //因为这里需要返回一个vector，即使它是空的。
        }
        */
        
        queue<TreeNode*> q;     //层序遍历的辅助队列
        q.push(pRoot);
        bool even = false;
        while( !q.empty() ){
            vector<int> vec;	//因为返回的是vector<vector<int> >
            const int size = q.size();
            for(int i=0; i<size; ++i){  //利用for循环把当前队列q中的元素取出来
                TreeNode* tmp = q.front();
                q.pop();
                vec.push_back(tmp->val);

                if(tmp->left != NULL)
                    q.push(tmp->left);
                if(tmp->right != NULL)
                    q.push(tmp->right);
            }
            if(even)
                //std::reverse(vec.begin(), vec.end());	//在最后使用reverse的时候复杂度要增加 虽然方便 但是却不是面试时候的最优解还是用栈
                
            result.push_back(vec);
            even = !even;

        }
        return result;
    }
    
};


//改进：如果偶数层的话，用insert插入vector最前面，不必使用reverse，减少复杂度。
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
```





### Code2 来自剑指offer

**日期**：2020.01.19

**方法**：按照刷题基础的说明，简明扼要说明方法是什么，用了什么数据结构等等。

**具体思路**：

**Code**：

```c++

```

