#include<iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):
        val(x), next(NULL){

        }
};

// 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
/*
  在当前结点的情况下：
    若下一个结点不为空：
        
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead){
        if( pHead == NULL ){
            return NULL;
        }

        ListNode *preNode = pHead, *startNode = pHead, *p = pHead;  //startNode表示重复结点开始指针，p表示工作指针，preNode始终表示startNode的前一个结点
        while( p->next ){
            p = p->next;
            
            while( startNode->val != p->val ){
                preNode = startNode;
                startNode = startNode->next;
                p = p->next;
            }
            while( startNode->val == p->val ){
                p = p->next;
            }
            preNode->next = p;
            startNode = p;
            
        }

        return pHead;

    }
};

int main(){
    ListNode list[7] = {1, 2, 3, 3, 4, 4, 5};
    list[0].next = &list[1];
    list[1].next = &list[2];
    list[2].next = &list[3];
    list[3].next = &list[4];
    list[4].next = &list[5];
    list[5].next = &list[6];
    list[6].next = &list[7];
    list[7].next = NULL;

    Solution solution;
    solution.deleteDuplication(list);

    return 0;
}