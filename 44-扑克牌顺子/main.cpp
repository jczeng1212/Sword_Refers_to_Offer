#include<vector>
using namespace std;

/*
链接：https://www.nowcoder.com/questionTerminal/762836f4d43d43ca9deb273b3de8e1f4?f=discussion
来源：牛客网
若numbers中有重复的数字，则不可能构成顺子，则返回false;
若max - min < 5，则不可能构成顺子，返回false
*/
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() < 5) {
            return false;
        }

        int d[14] = {0};  //记录numbers数组中每个数的个数，初始均为0
        d[0] = -4;  //数字0可以重复5次

        //max和min记录最大最小值，且均不初始化为0，且在后面的更新中，max和min没有变为0的可能
        //牌中的数字范围为1~13
        int max = -1;
        int min = 14;

        for (int i = 0; i < numbers.size(); i++) {
            d[ numbers[i] ] ++;
            if (numbers[i] == 0) {
                continue;
            }
            if (d[numbers[i]] > 1) {    //若有某个除零外的数字重复了,则return false
                return false;
            }

            if (numbers[i] > max) { //  记录最大值
                max = numbers[i];
            }
            if (numbers[i] < min) { //记录最小值
                min = numbers[i];
            }

        }

        if (max - min < 5) {
            return true; 
        } else {
            return false;
        }
        
    }
};

//【未通过】
//我的思路：max记录最大值，min记录最小值，(max-min+1)-非零数的个数得到需要大小王的个数，然后和0的个数进行比较
//因此需要记录零的个数
//需要记录非零的个数
//且非零数中不能含有重复数字
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() < 5) {
            return false;
        }

        int max = -1;
        int min = 14;
        int num0 = 0;   //记录0的个数
        int not0 = 0;   //记录非零的个数
        
        int d[14] = {0};  //记录numbers数组中每个数的个数，初始均为0
        d[0] = -4;  //数字0可以重复5次

        for (int i = 0; i < numbers.size(); i++) {
            d[numbers[i]]++;

            if (d[numbers[i]] > 1) {
                return false;
            }

            if (numbers[i] == 0) {
                num0++;
                continue;
            }
            not0++;
            if (d[numbers[i]] > 1) {    //若有某个除零外的数字重复了,则return false
                return false;
            }

            if (numbers[i] > max) { //  记录最大值
                max = numbers[i];
            }
            if (numbers[i] < min) { //记录最小值
                min = numbers[i];
            }
        }//for

        if (num0 == not0) {
            return true;
        } else {
            return false;
        }
    }
};
