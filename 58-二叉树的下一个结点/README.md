# 58-二叉树的下一个结点

牛客网链接：[58-二叉树的下一个结点](http://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=11210&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

题目描述

> 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
>
> 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。



## 1.一刷情况

**日期**：2019.09.18

**Code**：

```c++
//看过思路后，自己按照思路写的代码
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode){
        if( pNode == NULL ){
            return NULL;
        }

        //若该结点有右子树，则其右子树的最左边的结点就为其中序遍历的下一个结点
        if( pNode->right != NULL ){
            TreeLinkNode *node = pNode->right;
            while( node->left != NULL ){
                node = node->left;
            }
            return node;
        }//if

        //若该结点无右子树，且该结点为其父结点的左子结点，则该结点的父结点就为其中序遍历的下一个结点
        if( pNode->right == NULL && pNode->next != NULL && pNode->next->left == pNode ){
            return pNode->next;
        }//if

        //若该结点无右子树，且该结点为其父结点的右子结点，则沿着该结点的父指针向上找，直到找到一个结点A是结点A的父结点的左子结点，那么结点A的父结点就是中序遍历的下一个结点
        if( pNode->right == NULL && pNode->next != NULL && pNode->next->right == pNode ){
            TreeLinkNode *node = pNode->next;
            while( node->next != NULL && node->next->left != node ){
                node = node->next;
            }
            return node->next;
        }//if
    }
};


//改进的代码，该代码可以AC。
//看过思路后，自己按照思路写的代码
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode){
        if( pNode == NULL ){
            return NULL;
        }
        
        TreeLinkNode *pNext = NULL; //主要是加了这行就可以

        //若该结点有右子树，则其右子树的最左边的结点就为其中序遍历的下一个结点
        if( pNode->right != NULL ){
            TreeLinkNode *node = pNode->right;
            while( node->left != NULL ){
                node = node->left;
            }
            //return node;
            pNext = node;  //主要是加了这行就可以
        }//if

        //若该结点无右子树，且该结点为其父结点的左子结点，则该结点的父结点就为其中序遍历的下一个结点
        if( pNode->right == NULL && pNode->next != NULL && pNode->next->left == pNode ){
            pNext = pNode->next;
        }//if

        //若该结点无右子树，且该结点为其父结点的右子结点，则沿着该结点的父指针向上找，直到找到一个结点A是结点A的父结点的左子结点，那么结点A的父结点就是中序遍历的下一个结点
        if( pNode->right == NULL && pNode->next != NULL && pNode->next->right == pNode ){
            TreeLinkNode *node = pNode->next;
            while( node->next != NULL && node->next->left != node ){
                node = node->next;
            }
            pNext = node->next; //主要是加了这行就可以
        }//if
        
        return pNext; //主要是加了这行就可以
    }
};
```

**掌握情况**：完全不会，代码未写出

**存在问题**：初次见到这种题目





## 参考Code

### Code1 

**日期**：2019.09.18

**方法**：这里的思维导图思想来自剑指offer原书![2020-01-05_025950.png](https://i.loli.net/2020/01/06/3VWwXl9CqJAcQTs.png)

**具体思路**：

![bst.png](https://i.loli.net/2019/09/18/mohk5bgq7NnWfMS.png)

分三种情况：

- 一个结点有右子树：其中序遍历的下一个结点就是其右子树的最左结点。

  > 比如结点2中序遍历的下一个结点是3。

- 一个结点没有右子树，且

  - 该结点是它父结点的左子结点：其中序遍历的下一个结点就是他的父亲结点。

    > 比如结点1中序遍历的下一个结点是2。

  - 该结点是它父结点的右子结点：其下一个结点应该是当前结点所在的左子树的根，可以顺着其父节点一直向上遍历，直到找到一个结点满足这样的性质：它是它父结点的左子结点。那么满足该性质的结点的父结点就是我们所要找的结点。

    >  例，为了找到图中结点3的下一个结点，沿着指向父结点的指针向上遍历，达到结点2，由于结点2是它父结点4的左子结点，因此结点3中序遍历的下一个结点是4。
    >
    > 又例，为了找到图中结点9的下一个结点，沿着指向父结点的指针向上遍历，达到结点5，但由于结点5是它父结点4的右子结点，我们继续向上遍历到达结点4，由于结点4是树的根结点，它没有父结点。因此结点9没有下一个结点。



**Code**：

```c++
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode){
        if( pNode == NULL ){
            return NULL;
        }

        TreeLinkNode *pNext = NULL;

        //若该结点有右子树，则其右子树的最左边的结点就为其中序遍历的下一个结点
        if( pNode->right != NULL ){
            TreeLinkNode *node = pNode->right;
            while( node->left != NULL ){
                node = node->left;
            }
            pNext = node;
        }//if

        /*
            若该结点无右子树，顺着其父节点一直向上遍历，直到找到一个结点满足这样的性质：它是它父结点的左子结点。那么满足该性质的结点的父结点就是我们所要找的结点。
            这里和思路不同的是，将结点无右子树下的两种情况合并起来处理了。
        */
        else if( pNode->right == NULL && pNode->next != NULL ){
            TreeLinkNode *pCurrent = pNode;
            TreeLinkNode *pParent = pNode->next;
            while( pParent != NULL && pCurrent == pParent->right ){
                pCurrent = pParent;
                pParent = pParent->next;
            }
            pNext = pParent;
        }

        return pNext;

    }
};
```


