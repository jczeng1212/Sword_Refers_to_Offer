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
class Solution{
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
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

int main(){

    return 0;
}