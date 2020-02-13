#include<stack>
using namespace std;

class Solution {
public:
    void push(int value) {
        
    }
    void pop() {
        
    }
    int top() {
        
    }
    int min() {
        
    }
};



//链接：https://www.nowcoder.com/questionTerminal/4c776177d2c04c2494f2555c9fcc1e49?f=discussion
//来源：牛客网

class Solution {
public:
     
    stack<int> stack1, stack2;
    //stack1为数据栈
    //stack2为辅助栈，保证stack2栈的栈顶为最小元素
     
    void push(int value) {
        stack1.push(value);
        if(stack2.empty())  //  为空直接压入
            stack2.push(value);
        else if (value <= stack2.top()) //新压入的值比stack2栈顶值还小，则压入s
        {
            stack2.push(value);
        }
    }
     
    void pop() {
        if(stack1.top()==stack2.top())  //stack2栈的栈顶始终为最小值，若此时stack1栈顶为最小值，那么stack2栈顶就要弹出
            stack2.pop();
        stack1.pop();
         
    }
    
    int top() {
        return stack1.top();  
    }
     
    int min() {
        return stack2.top();
    }
     
};
