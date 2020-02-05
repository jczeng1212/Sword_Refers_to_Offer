#include<vector>
using namespace std;

//代码来自剑指offer
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if( data.empty() ){
            return;
        }

        int resultExclusiveOR = 0;  //保存数组中所有数字的异或结果
        for( int i = 0; i < data.size(); i++){
            resultExclusiveOR ^= data[i];
        }

        unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR); //找出结果中从右到左第一个为1的位置indexOf1

        *num1 = *num2 = 0;
        for( int j = 0; j < data.size(); j++){
            if( IsBit1(data[j], indexOf1) )
                *num1 ^= data[j];
            else
                *num2 ^= data[j];
        }
    }

    //找到从右到左第一个为1的位置
    unsigned int FindFirstBitIs1(int num){
        int indexBit = 0;
        while( ((num & 1) == 0) && (indexBit < 8 * sizeof(int)) ){
            num = num >> 1;
            indexBit++;
        }

        return indexBit;
    }

    //判断第indexBit位是否为1
    bool IsBit1(int num, unsigned int indexBit){
        num = num >> indexBit;
        return (num & 1);
    }
};