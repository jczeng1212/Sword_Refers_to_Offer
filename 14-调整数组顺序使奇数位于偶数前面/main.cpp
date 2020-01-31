#include<iostream>
#include<queue>
using namespace std;

//【解法1】
//利用两个队列：将偶数放入一个队列，将奇数放入另外一个队列
//最后，将两个队列中的元素依次按照题目要求放入vector的array中

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        //判空
        //if( array.size() == 0 ){
        //    
        //}
        
        queue<int> q1, q2;
        for( int i=0; i<array.size(); i++){
            if( array[i]%2 == 0 ){
                //偶数放入q1
                q1.push(array[i]);
            }else{
                //奇数放入q2
                q2.push(array[i]);
            }//if
        }//for

        array.clear();
        while( !q2.empty() ){
            array.push_back(q2.front());
            q2.pop();
        }
        while( !q1.empty() ){
            array.push_back(q1.front());
            q1.pop();
        }
        
    }
};

//【解法2】一种类似于插入排序的in-place做法
//【暂时有BUG】
//从头到尾遍历该数组，每遇到一个偶数，就将该偶数拿出来，再将后面的所有数字向前移动一位，再将该偶数放到最后一位上。
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        for( int i=0; i<array.size(); ){
            if( array[i]%2 == 0 ){
                int even = array[i];
                int j = i;
                while( j < array.size()-1 ){
                    array[j] = array[j+1];
                    j++;
                }
                array[j] = even;
                
            }else{
                i++;
            }
        }
        
    }
};