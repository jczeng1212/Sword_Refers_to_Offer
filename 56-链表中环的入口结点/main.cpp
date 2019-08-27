#include<iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):
        val(x), next(NULL){

        }
};

/*
    step1.先判断链表中是否有环。设置两个指针，一快一慢，这里设置快一步。
        若有环，则两个指针一定相遇于环内，然后同时移动并计数，当再次回到该结点时，就求出环长circleLen；若没有，返回NULL；
    step2.设置两个指针p1和p2，其中p1先走circleLen步，然后p1和p2同时走，然后他们相遇，相遇的结点就是环的入口结点
*/

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead){
        if( pHead == NULL ){
            return NULL;
        }

        int circleLen = GetCircleLength(pHead);
        
        if( circleLen == 0 ){   //环长为0，则表示无环
            return NULL;
        }

        ListNode *p1 = pHead;
        ListNode *p2 = pHead;
        while( circleLen ){ //让p2先走环长步
            p2 = p2->next;
            circleLen--;
        }
        
        while( p2 ){
            if( p2->val == p1->val ){
                return p2;
            }

            p2 = p2->next;
            p1 = p1->next;
        }
        
    }

private:
    int GetCircleLength(ListNode *pHead){
        ListNode *quickP = pHead;
        ListNode *lowP = pHead;
        quickP = quickP->next;

        int count = 0;
        while( quickP ){
            if (quickP->val == lowP->val ){                
                int commonNode = quickP->val;
                
                lowP = lowP->next;
                while( lowP->val != commonNode ){
                    count++;
                    lowP = lowP->next;
                }
                count++;
                break;                
            }else{
                lowP = lowP->next;
                quickP = quickP->next->next;    //【注意！】不是 quickP = quickP->next;就可以了
            }
        }
        return count;
    }

};

int main(){
    ListNode list[5] = {0, 1, 2, 3, 4};
    list[0].val = 0;
    list[0].next = &list[1];
    list[1].val = 1;
    list[1].next = &list[2];
    list[2].val = 2;
    list[2].next = &list[3];
    list[3].val = 3;
    list[3].next = &list[4];
    list[4].val = 4;
    list[4].next = &list[1];


    return 0;
}