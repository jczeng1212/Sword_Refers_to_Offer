/*
    思考：本题需要建树吗？不需要，只要后序序列满足那种特性即可。
*/

#include<iostream>
#include<vector>
using namespace std;

//自己写的方法，牛客网报错如下：
/*
    答案错误:您提交的程序没有通过所有的测试用例
    case通过率为87.50%

    用例:
    []

    对应输出应该为:

    false

    你的输出为:

    true
*/
//应如何修改？
class Solution1{
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        
        if( sequence.size() == 0 ){
            return false;
        }
        
        int lastPos = sequence.size();
        int root = sequence[lastPos-1];
        cout << root << endl;

        vector<int> left;
        vector<int> right;

        int rightStart = -1;
        for(int i = 0; i < sequence.size(); i++){
            if( sequence[i] < root ){
                left.push_back(sequence[i]);
            }else{
                rightStart = i;
                break;
            }
        }
        for(int i = rightStart; i < sequence.size() - 1; i++){
            if( (sequence[i] > root) == false ){
                return false;
            }
            right.push_back(sequence[i]);
        }


        return VerifySquenceOfBST(left) && VerifySquenceOfBST(right);
        
    }
};


class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return bst(sequence, 0, sequence.size() - 1);
    }

private:
    bool bst(vector<int> seq, int begin, int end){
        if(seq.empty() || begin > end){
            return false;
        }
        
        //根结点
        int root = seq[end];
        
        //在二叉搜索树中左子树的结点小于根结点
        int i = begin;
        for(; i < end; ++i){
            if(seq[i] > root){
                break;
            }
        }
        
        //在二叉搜索书中右子树的结点大于根结点
        for(int j = i; j < end; ++j){
            if(seq[j] < root){
                return false;
            }
        }
        
        //递归判断左子树是不是二叉搜索树
        bool left = true;
        if(i > begin){
            left = bst(seq, begin, i - 1);
        }
        
        //递归判断右子树是不是二叉搜索树
        bool right = true;
        if(i < end - 1){
            right = bst(seq, i , end - 1);
        }
        
        return left && right;
    }
};

int main(){

    vector<int> sequence;
    //int postOrder[] = {5, 7, 6, 9, 11, 10, 8};
    int postOrder[] = {7, 4, 6, 5};
    
    //将后续遍历序列放进sequence中
    for(int i = 0; i < 7; i++ ){
        sequence.push_back(postOrder[i]);
    }


    Solution solution;
    if (solution.VerifySquenceOfBST(sequence)) {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    

    return 0;
}