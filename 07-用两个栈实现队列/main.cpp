#include<iostream>
#include<stack>
using namespace std;


class Solution{
public:
    void push(int node){
        stack1.push(node);
    }

    int pop(){
        
        //当stack2为空的时候，将stack1中的元素全部倒入stack2中
        //当stack2不为空的时候，直接将stack2中元素出栈
        if( stack2.empty() == true ){
            /* 按下面这种方式写代码会产生错误。原因在于：stack1在不断地pop，大小在变化，不能拿来做for循环的循环条件
            for(int i = 0; i < stack1.size(); i++ ){
                //cout << stack1.top() << " ";
                
                value = stack1.top();
                stack1.pop();
                stack2.push(value);
            }
            */
           
           //将stack1中元素全部倒入stack2中
           while(stack1.empty() != true){
                    int temp = stack1.top( );
                    stack1.pop();
                    stack2.push(temp);
            }

        }
        int value =  stack2.top();
        stack2.pop();
            
        
        return value;
    }

private:
    stack<int> stack1;
    stack<int> stack2;

};


int main(){
    Solution solution;
    solution.push(1);
    solution.push(2);
    solution.push(3);
    solution.push(4);
    solution.push(5);

    for(int i = 0; i < 5; i++){       
        cout << solution.pop() << " ";
    }
    cout << endl;


    return 0;
}