#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct ListNode {
      int val;
      struct ListNode *next;
      /*
      ListNode(int x) :
           val(x), next(NULL) {
      }
      */
};

//方法一：使用栈
class Solution1 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        
        int count = 0;  //给链表元素计数
        stack<int> st;
        ListNode *node = head;

        while(node != NULL){
            st.push(node->val);
            node = node->next;
            count++;
        }

        vector<int> res(count); //开辟静态vector
        
        for(int i = 0; i < count && st.empty() != true; i++){
            res[i] = st.top();
            st.pop();
        }
        
        return res;
        
    }
};


//方法二：使用递归
class Solution2{
public:
    vector<int> printListFromTailToHead(ListNode* head){
        vector<int> res;
        printListFromTailToHeadRecursion(head, res);

        return res;
    }

    void printListFromTailToHeadRecursion(ListNode* head, vector<int> &res){
        if( head != NULL ){
            printListFromTailToHeadRecursion(head->next, res);
            res.push_back(head->val);
        }
    }

};




//方法三：更精简的递归
class Solution{
public:
    vector<int> res;
    vector<int> printListFromTailToHead(ListNode* head){
        if(head != NULL ){
            printListFromTailToHead( head->next );
            res.push_back(head->val);
        }
        
        return res; //这样在下面的输出中，会返回多次res，只不过每次后面的返回的都会把前面的给覆盖了，因此就感觉只返回了一次res
    }

};

int main(){
    ListNode list[4];
    list[0].val = 0;
    list[0].next = &list[1];
    list[1].val = 1;
    list[1].next = &list[2];
    list[2].val = 2;
    list[2].next = &list[3];
    list[3].val = 3;
    list[3].next = &list[4];
    list[4].val = 4;
    list[4].next = NULL;

    
    Solution solution;
    vector<int> res = solution.printListFromTailToHead(list);
    
    vector<int>::iterator it;   //使用迭代器输出
    for(it = res.begin(); it != res.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}