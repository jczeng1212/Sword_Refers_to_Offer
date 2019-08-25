#include<iostream>
using namespace std;


struct ListNode{
    int val;
    struct ListNode *next;
    ListNode (int x):
        val(x), next(NULL){

        }
    
};

/*
    若p1上元素比p2上的大，则p2指针后移
    若p1上元素比p2上的小，则p1指针后移
    ==》即，谁的指针上的值小，谁后移
    后移后，再进行比较
    最后，对p1和p2判空，若不空（肯定有一个为空，有一个不空），则加入新的链表中。
*/
class Solution1{
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        if( pHead1 == NULL ){
            return pHead2;
        }
        if( pHead2 == NULL ){
            return pHead1;
        }

        //创建新链表头结点
        ListNode *pHead = new ListNode(-1);
        pHead->next = NULL;
        ListNode *s = pHead;    //设置链表的尾指针
        
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;

        while( p1 != NULL && p2 != NULL ){
            if( p1->val >= p2->val ){
                //尾插法，仅将较小值插入
                ListNode *temp = new ListNode( p2->val );
                s->next = temp;
                s = temp;

                //较小值处指针后移
                p2 = p2->next;
            }else{
                //尾插法，仅将较小值插入
                ListNode *temp = new ListNode( p1->val );
                s->next = temp;
                s = temp;

                //较小值处指针后移
                p1 = p1->next;

            }
        }

        while( p1 ){
            //若p1链表剩余还有，则采用尾插法将剩余元素插入
            ListNode *temp = new ListNode(p1->val);
            s->next = temp;
            s = s->next;
            
            p1 = p1->next;
        }
        while( p2 ){
            //若p1链表剩余还有，则采用尾插法将剩余元素插入
            ListNode *temp = new ListNode(p2->val);
            s->next = temp;
            s = s->next;
            
            p2 = p2->next;
        }

        return pHead->next;
        
    }

};


/*
    另一种方法:
    step1.先判断边界
    step2.从头遍历链表，判断当前指针，哪个链表中的值小，即赋给合并链表指针即可。使用递归实现。
*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        //判断指针是否为空
        if(pHead1 == NULL){
            return pHead2;
        }
        else if(pHead2 == NULL){
            return pHead1;
        }

        ListNode* pMergedHead = NULL;
        if(pHead1->val < pHead2->val){
            pMergedHead = pHead1;
            pMergedHead->next = Merge(pHead1->next, pHead2);
        }else{
            pMergedHead = pHead2;
            pMergedHead->next = Merge(pHead1, pHead2->next);
        }

        return pMergedHead;
    }
};

int main(){

    return 0;
}