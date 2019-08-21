#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

//定义两个指针
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        //这里要注意代码的鲁棒性！否则牛客网上不通过！
        if( pListHead == NULL || k == 0 ){
            return NULL;
        }

        k = k - 1;
        ListNode *p1 = pListHead;
        while( k-- ){
            p1 = p1->next;
            if ( p1 == NULL ){  //这里要注意代码的鲁棒性！否则牛客网上不通过！
                return NULL;
            }
        }

        ListNode *p2 = pListHead;

        while( p1->next != NULL ){
            p1 = p1->next;
            p2 = p2->next;
        }

        return p2;
    }
};

int main(){


    return 0;
}