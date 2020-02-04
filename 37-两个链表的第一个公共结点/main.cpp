#include<iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):
        val(x), next(NULL){

        }
};

class  Solution{
public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2){
        if( pHead1 == NULL || pHead2 == NULL ){
            return NULL;
        }

        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;

        int len1 = GetListLength(pHead1);
        int len2 = GetListLength(pHead2);
        int len = (len1 > len2) ? (len1 - len2 ):(len2 - len1);
        while( len ){
            if( len1 > len2 ){
                p1 = p1->next;
            }else{
                p2 = p2->next;
            }
            len--;
        }

        while( p1 ){
            if( p1->val == p2->val ){
                return p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        return NULL;
    }

    int GetListLength(ListNode *pHead){
        if( pHead == NULL ){
            return 0;
        }
        ListNode *p = pHead;
        int length = 0;
        while( p ){
            length++;
            p = p->next;
        }

        return length;
    }
};