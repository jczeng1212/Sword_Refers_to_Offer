#include<iostream>
using namespace std;

struct RandomListNode{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x):
        label(x), next(NULL), random(NULL){

        }
};

/*
    效率最优的方法:时间复杂度O(n)，空间复杂度S(1)
    step1.根据原始链表的每个结点N创建对应的N'，并把N'链接在N的后面；
    step2.设置复制出来的结点的random指针；
    step3.将这个长链表拆分成两个链表：奇数位置上的结点组成原始链表，偶数位置上的结点组成复制出来的链表
*/
class Solution{
public:
    RandomListNode* Clone(RandomListNode *pHead){
        if( pHead == NULL ){
            return NULL;
        }
        
        RandomListNode *head = CreateLinkList(pHead);
        SetRandomPointer(head);
        //RandomListNode *cloneHead = SplitRandomList(head);
        RandomListNode *cloneHead = ReconnectNodes(head);
        return cloneHead;
    }

private:
    //step1 function
    RandomListNode* CreateLinkList(RandomListNode *pHead){
        RandomListNode *p = pHead;  //设置工作指针
        while( p ){
            //插入新结点
            RandomListNode *temp = new RandomListNode( p->label );
            temp->random = NULL;
            temp->next = p->next;
            p->next = temp;

            //将p工作指针后移两步
            p = p->next->next;
            
        }
        return pHead;
    }

    //step2 function
    void SetRandomPointer(RandomListNode *pHead){
        RandomListNode *p = pHead;  //设置工作指针
        while( p ){
            if( p->random != NULL ){
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
    }

    //step3 function
    /*  这个函数写的有问题
    RandomListNode *SplitRandomList(RandomListNode *pHead){
        RandomListNode *p = pHead;
        p = p->next;
        while( p ){
            p->next = p->next->next;
            p = p->next->next;
        }

        return pHead->next;
    }
    */

   
   RandomListNode* ReconnectNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        RandomListNode* pClonedHead = NULL;
        RandomListNode* pClonedNode = NULL;
        
        if(pNode != NULL){
            pClonedHead = pClonedNode = pNode->next;
            
            pNode->next = pNode->next->next;
            pNode = pNode->next;
        }
        
        while(pNode != NULL){
            pClonedNode->next = pNode->next;
            pClonedNode = pClonedNode->next;
            
            pNode->next = pNode->next->next;
            pNode = pNode->next;
        }
        return pClonedHead;
    }
};

int main(){
    RandomListNode list[5] = {1,2,3,4,5}; //注意这里要进行初始化
    //list[0].label = 0;
    list[0].next = &list[1];
    list[0].random = &list[3];

    //list[1].label = 1;
    list[1].next = &list[2];
    list[1].random = NULL;

    //list[2].label = 2;
    list[2].next = &list[3];
    list[2].random = NULL;

    //list[3].label = 3;
    list[3].next = &list[4];
    list[3].random = &list[1];

    //list[4].label = 4;
    list[4].next = NULL;
    list[4].random = NULL;

    
    Solution solution;
    RandomListNode *p = solution.Clone(list);
    while( p ){
        cout << p->label << " ";
        p = p->next;
    }
    
    cout << endl;



    return 0;
}