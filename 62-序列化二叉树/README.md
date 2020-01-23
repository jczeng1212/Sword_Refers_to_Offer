# 62-序列化二叉树

牛客网链接：[62-序列化二叉树](http://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?tpId=13&tqId=11214&rp=4)

题目描述

> 请实现两个函数，分别用来序列化和反序列化二叉树
>
> 二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），以 ！ 表示一个结点值的结束（value!）。
>
> 二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。



## 1.一刷情况

**日期**：2020.01.22

**Code**：

```c++

```

**掌握情况**：完全不会

**存在问题**：





## 参考Code

### Code1 

**日期**：2020.01.22

**方法**：

**具体思路**：

**Code**：

```c++
class Solution {
    vector<int> buf;
    void dfs( TreeNode* p){
        if(!p) 
            buf.push_back(0x23333);
        else{
            buf.push_back(p -> val);
            dfs(p -> left);
            dfs(p -> right);
        }
    }

    TreeNode* dfs2( int*& p){
        if(*p == 0x23333){
            ++p;
            return NULL;
        }
        TreeNode* res = new TreeNode(*p);
        ++p;
        res -> left = dfs2(p);
        res -> right = dfs2(p);
        return res;
    }

public:
    char* Serialize(TreeNode *p) {
        buf.clear();
        dfs(p);
        int *res = new int[buf.size()];
        for(unsigned int i = 0; i < buf.size(); ++i)
            res[i] = buf[i];
        return (char*)res;
    }
    TreeNode* Deserialize(char *str) {
        int *p = (int*)str;
        return dfs2(p);
    }
};
```


