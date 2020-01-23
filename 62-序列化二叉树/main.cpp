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


//思考：本题涉及二叉树的遍历及从遍历结果恢复二叉树。


class Solution {
public:
    char* Serialize(TreeNode *root) {    
        
    }
    TreeNode* Deserialize(char *str) {
    
    }
};



//来自牛客网讨论区


class Solution {
    vector<int> buf;
    void dfs( TreeNode* p){
        if( !p ) 
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