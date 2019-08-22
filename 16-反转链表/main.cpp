#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode( int x ):
        val(x), next(NULL){

        }
};

/* 我的方法：
    1.将链表遍历，同时将链表值顺序送入一个vector中
    2.重建一个链表，采用头插法建立一个链表，插入元素顺序从头到尾在vector中取出
*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if( pHead == NULL ){
            return NULL;
        }

        vector<int> temp;
        ListNode *p = pHead;
        while( p ){
            temp.push_back( p->val );
            p = p->next;
        }

        ListNode *head = new ListNode(-1);
        head->next = NULL;
        
        for( int i = 0; i < temp.size(); i++ ){
            ListNode *s = new ListNode(temp[i]);
            s->next = head->next;
            head->next = s;
        }

        return head->next;
    }
};

/*
    另一种思路：
    利用三个指针
    pPrev -> pNode -> pNext; 我们先保存原来的下一个指针位置，要不然翻转后其next会指向pPrev，
    从而丢失指向pNext的指针 接着反转指针， 然后下面指针同步后移，以便处理后面的指针
*/
class Solution1 {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pReversedHead = NULL;
        
        ListNode* pNode = pHead;
        ListNode* pPrev = NULL;

        while( pNode != NULL ){
            ListNode* pNext = pNode->next;  //保存其下一个节点
            if( pNext == NULL ){
                pReversedHead = pNode;
            }
            pNode->next = pPrev;    //指针指向反转
            pPrev = pNode;          //保存前一个指针
            pNode = pNext;          //递增指针, 指向下一个结点
        }
        return pReversedHead;
    }
};