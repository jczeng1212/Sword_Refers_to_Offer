#include<vector>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

//中序遍历，然后第k个结点就是答案
//在递归返回时，第k次返回时，得到答案
//链接：https://www.nowcoder.com/questionTerminal/ef068f602dde4d28aab2b210e859150a?f=discussion
//来源：牛客网

class Solution {
    int count = 0;
public:
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        if(pRoot){ 
                TreeNode *ret = KthNode(pRoot->left, k);
                if(ret) return ret;
                if(++count == k) return pRoot;
                ret = KthNode(pRoot->right,k);
                if(ret) return ret;
        }
        return nullptr;
    }
};


class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        TreeNode* res = nullptr;
        if (!k)
            return res;

        count = k;
        
        res = inOrder(pRoot);

        return res;
    }

private:
    int count = 0;
    TreeNode* inOrder(TreeNode* pRoot) {
        
        if (pRoot == nullptr) {    
            return nullptr;
        }
        
        inOrder(pRoot->left);
        --count;
        if (count == 0)
            return pRoot;
        
        inOrder(pRoot->right);

    }
};



//链接：https://www.nowcoder.com/questionTerminal/ef068f602dde4d28aab2b210e859150a?f=discussion
//来源：牛客网

class Solution {
public:
    //中序遍历的结果就是有序序列，第K个元素就是vec[K-1]存储的节点指针；
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        if(pRoot==NULL||k<=0) return NULL;
        vector<TreeNode*> vec;
        Inorder(pRoot,vec);
        if(k>vec.size())
            return NULL;
        return vec[k-1];
    }
    //中序遍历，将节点依次压入vector中
    void Inorder(TreeNode* pRoot,vector<TreeNode*>& vec)
    {
        if(pRoot==NULL) return;
        Inorder(pRoot->left,vec);
        vec.push_back(pRoot);
        Inorder(pRoot->right,vec);
    } 
};