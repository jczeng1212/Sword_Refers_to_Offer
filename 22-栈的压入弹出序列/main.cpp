#include<vector>
#include<stack>
#include<iostream>
using namespace std;


//主要不可能的地方在先压入的比后压入的先出来。比如，压入1、2，结果弹出也为1、2
//根据popV的第一个元素popV[0]，可以确定在pushV中popV[0]之前的元素已压入，
//若popV中popV[0]后面的元素中出现了已压入元素的逆序列，则return false;
//怎么确定已压入元素的逆序列呢？
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        
    }
};



//链接：https://www.nowcoder.com/questionTerminal/d77d11405cc7470d82554cb392585106?f=discussion
//来源：牛客网
//建立一个辅助栈
class Solution1 {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() == 0) return false;
        vector<int> stack;  //设置一个辅助栈，用vector实现，
        for (int i = 0, j = 0 ; i < pushV.size();) {
            stack.push_back( pushV[i++] );    //将pushV中元素放入stack中
            while (j < popV.size() && stack.back() == popV[j]) {    //stack.back()表示辅助栈的栈顶
                stack.pop_back();
                j++;
            }      
        }
        return stack.empty();
    }
};



//链接：https://www.nowcoder.com/questionTerminal/d77d11405cc7470d82554cb392585106?f=discussion
//来源：牛客网
/*C++
模拟堆栈操作：将原数列依次压栈，栈顶元素与所给出栈队列相比，如果相同则出栈，
如果不同则继续压栈，直到原数列中所有数字压栈完毕。
检测栈中是否为空，若空，说明出栈队列可由原数列进行栈操作得到。否则，说明出栈队列不能由原数列进行栈操作得到。
*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty() || popV.empty() || pushV.size()!=popV.size())
            return false;
        stack<int> s;
        int j=0;
        for(int i=0;i<pushV.size();++i){
            s.push(pushV[i]);
            while(!s.empty()&&j<popV.size()&&s.top()==popV[j]){
                s.pop();
                ++j;
            }
        }
        if(s.empty())
            return true;
        return false;
    }
};

int main(){
    stack<int> s;
    

    return 0;
}