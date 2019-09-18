# 39-二叉树的深度

牛客网链接：[二叉树的深度](https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b?tpId=13&tqId=11191&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

题目描述

> 输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
>
> 

## 1.一刷情况

**日期**：2019.09.05

**Code**：

```c++
class Solution {
public:
    int maxDepth = 0;
    int depth;
    
    int TreeDepth(TreeNode* pRoot){
        if( pRoot == NULL ){
            return true;
        }

        if( pRoot->left == NULL && pRoot->right == NULL ){
            depth++;    //到达叶结点，则深度加一
            if( depth > maxDepth ){
                maxDepth = depth;
            }
        }//if

        depth = 0;
        TreeDepth(pRoot->left);
        TreeDepth(pRoot->right);

        return maxDepth;
    }
};
```

**掌握情况**：完全不会

**存在问题**：

> 递归写的有误。
>
> 问题所在：
>
> 1.不必单独去判断是否到达叶子结点。那就不必设置depth变量。





## 参考Code

本题方法：递归、层序遍历。



### Code1

**日期**：2019.09.05

**方法**：递归

**具体思路**：

> 这里的递归理解起来就是：
>
> 如果一棵树只有一个结点，它的深度为1；
>
> 如果根结点只有左子树而没有右子树，那么树的深度为其左子树的深度+1；
>
> 如果根结点只有右子树而没有左子树，那么树的深度为其右子树的深度+1；
>
> 如果既有左子树又有右子树，那么树的深度就为max(左子树深度, 右子树深度) + 1；

**Code**：

```c++
//递归方法一：
class Solution {
public:
    int TreeDepth(TreeNode* pRoot){
        /*
        这里的条件判断应该有两层含义：
        1.对第一次的pRoot判断是否为空树
        2.后面，当pRoot为NULL时，表明深度为0。即pRoot为叶子的结点，其深度为0
        */
        if( pRoot == NULL ){
            return 0;
        }

        int depthLeft = TreeDepth(pRoot->left);
        int depthRight = TreeDepth(pRoot->right);

        return max(depthLeft, depthRight) + 1;
    }
};

//递归方法二：将depth变量当做递归函数参数
class Solution {
public:
    int TreeDepth(TreeNode* pRoot, int depth){
        if( pRoot == NULL ){
            return 0;
        }

        int depthLeft = TreeDepth(pRoot->left, depth + 1);
        int depthRight = TreeDepth(pRoot->right, depth + 1);

        return max(depthLeft, depthRight);
    }
};
```





### Code2

**日期**：2019

**方法**：层序遍历

**具体思路**：

> 
>
> 

**Code**：

```c++

```

