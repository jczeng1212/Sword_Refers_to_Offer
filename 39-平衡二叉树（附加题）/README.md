# 39-平衡二叉树（附加题）

牛客网链接：[39-平衡二叉树（附加题）](https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=11192&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

题目描述

> 输入一棵二叉树，判断该二叉树是否是平衡二叉树。



## 1.一刷情况

**日期**：2019.09.17

**Code**：

```c++
/*
平衡二叉树：树中的以任何结点为根的树都为平衡二叉树。
对树进行遍历，对每个结点做一次查询是否为平衡二叉树即可。
*/
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        

        if( pRoot->left ){
            IsBalanced_Solution( pRoot->left );
        }
        if( pRoot->right ){
            IsBalanced_Solution( pRoot->right );
        }
    }
};
```

**掌握情况**：完全不会

**存在问题**：不会写，思路不对





## 参考Code

### Code1 

**日期**：2019.09.017

**方法**：需要重复遍历结点多次

**具体思路**：见剑指offer

**Code**：

```c++
class Solution{
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if( pRoot == NULL ){
            return true;
        }

        int left = TreeDepth( pRoot->left );
        int right = TreeDepth( pRoot->right );

        int diff = left - right;

        if( diff > 1 || diff < -1 )
            return false;
        else
            return IsBalanced_Solution( pRoot->left ) && IsBalanced_Solution( pRoot->right );

    }

    int TreeDepth(TreeNode *pRoot){
        if( pRoot == NULL ){
            return 0;
        }

        int left = TreeDepth( pRoot->left );
        int right = TreeDepth( pRoot->right );

        return max(left, right) + 1;

    }
};
```

### Code2 

**日期**：2019.

**方法**：（未研究）每个结点仅遍历一次，见剑指offer

**具体思路**：

**Code**：

```c++

```

