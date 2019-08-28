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
    不通过
*/
class Solution1 {
public:
    ListNode* deleteDuplication(ListNode* pHead){
        if( pHead == NULL ){
            return NULL;
        }

        ListNode *preNode = pHead, *startNode = pHead, *p = pHead;  //startNode表示重复结点开始指针，p表示工作指针，preNode始终表示startNode的前一个结点
        //p结点走在最前面，一定要注意其p->next的有效性
        while( p->next ){
            //int firstNode = p->val;
            p = p->next;

            if( pHead->val == p->val && p->next == NULL ){
                return p;
            }
            
            while( startNode->val != p->val ){
                preNode = startNode;
                startNode = startNode->next;
                if( p->next ){
                    p = p->next;
                }
                
            }
            while( startNode->val == p->val ){
                if( p->next != NULL ){
                    p = p->next;
                }else{
                    break;
                }
                
            }
            preNode->next = p;
            startNode = p;
            
        }

        return pHead;

    }
};



class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead){
        if(pHead == NULL){
            return NULL;
        }

        // 指向当前结点前最晚访问过的不重复结点
        ListNode* pPre = NULL;
        
        // 指向当前处理的结点
        ListNode* pCur = pHead;
        
        // 指向工作结点，位于pCur之后
        ListNode* pNext = NULL;
        
        while(pCur != NULL){
            // 如果当前结点与下一个结点相同
            if(pCur->next != NULL && pCur->val == pCur->next->val){
                pNext = pCur->next;
                
                // 找到重复序列的最后一个结点位置，保存在pNext中
                while(pNext->next != NULL && pNext->next->val == pCur->val){
                    pNext = pNext->next;
                }

                // 如果pCur指向链表中第一个元素，pCur -> ... -> pNext ->... 
                // 要删除pCur到pNext, 将指向链表第一个元素的指针pHead指向pNext->next。
                if(pCur == pHead){
                    pHead = pNext->next;
                }else{
                    // 如果pCur不指向链表中第一个元素，pPre -> pCur ->...->pNext ->... 
                    // 要删除pCur到pNext，即pPre->next = pNext->next
                    pPre->next = pNext->next;
                }
                // 向前移动
                pCur = pNext->next;
            }else{
                // 如果当前结点与下一个结点不相同
                pPre = pCur;
                pCur = pCur->next;
            }
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