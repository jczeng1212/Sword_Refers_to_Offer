#include<iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

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


//改进的代码
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

//参考code1
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


int main(){

}