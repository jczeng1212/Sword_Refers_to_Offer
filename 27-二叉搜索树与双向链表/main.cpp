
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向
//因为需要转换成一个有序的双向链表，因此类似中序遍历过程，在遍历的过程中调整指针的指向
//
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree->left != nullptr){
            Convert(pRootOfTree->left);
        }
        


    }
};

//链接：https://www.nowcoder.com/questionTerminal/947f6eb80d944a84850b0538bf0ec3a5?f=discussion
//来源：牛客网
//中序遍历对节点的访问顺序和转换完链表从左到右的顺序是一样的。所以在中序遍历时完成相邻两个节点的互指即可。
//具体做法是把前一个节点记录下来然后pre->right = cur; cur->left = pre。
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr) return nullptr;
        TreeNode* pre = nullptr;    //记录当前结点的前一个结点
         
        convertHelper(pRootOfTree, pre);
        
        //res初始化为 pRootOfTree，所以while循环中不需要判断res是否为nullptr
        TreeNode* res = pRootOfTree;
        while(res ->left)
            res = res ->left;
        return res;
    }
     
    void convertHelper(TreeNode* cur, TreeNode*& pre)
    {
        if(cur == nullptr) return;
         
        //CovertHelper中没有判断cur->left, cur->right是否为nullptr，就直接递归，这样只是会多递归一次，不影响结果
        convertHelper(cur ->left, pre);
        
        //完成pre和cur的互指
        //pre在前，cur在后
        cur ->left = pre;
        if(pre) pre ->right = cur;
        pre = cur;  //更新pre
         
        convertHelper(cur ->right, pre);
         
         
         
    }
};