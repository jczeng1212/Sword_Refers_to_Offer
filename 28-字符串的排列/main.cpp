#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;

        if( str.empty() ){
            return result;
        }


    }
};


//链接：https://www.nowcoder.com/questionTerminal/fe6b651b66ae47d7acce78ffdd9a96c7?f=discussion
//来源：牛客网

class Solution {
public:
    vector<string> Permutation(string str){
        vector<string> result;
        if( str.empty() ) 
            return result;
        
        Permutation( str, result, 0);
         
        //此时得到的result中排列并不是字典顺序，可以单独再排下序
        sort( result.begin(), result.end());
         
        return result;
    }
     
    void Permutation(string str, vector<string> &result, int begin){
        if( begin == str.size() - 1 ){  // 递归结束条件：索引已经指向str最后一个元素时
            if( find( result.begin(), result.end(), str) == result.end() ){
                // 如果result中不存在str，才添加；避免aa和aa重复添加的情况
                result.push_back(str);
            }
        }else{
            // 第一次循环i与begin相等，相当于第一个位置自身交换，关键在于之后的循环，
            // 之后i != begin，则会交换两个不同位置上的字符，直到begin==str.size()-1，进行输出；
            for( int i = begin; i < str.size(); ++i){
                swap( str[i], str[begin]);
                Permutation( str, result, begin+1);
                swap( str[i], str[begin]); // 复位，用以恢复之前字符串顺序，达到第一位依次跟其他位交换的目的
            }
        }//if
    }
     
    void swap( char &fir, char &sec){
        char temp = fir;
        fir = sec;
        sec = temp;
    }
};



//链接：https://www.nowcoder.com/questionTerminal/fe6b651b66ae47d7acce78ffdd9a96c7?f=discussion
//来源：牛客网

/* 2、字典序排列算法
     *
     * 可参考解析： http://www.cnblogs.com/pmars/archive/2013/12/04/3458289.html  （感谢作者）
     *
     * 一个全排列可看做一个字符串，字符串可有前缀、后缀。
     * 生成给定全排列的下一个排列.所谓一个的下一个就是这一个与下一个之间没有其他的。
     * 这就要求这一个与下一个有尽可能长的共同前缀，也即变化限制在尽可能短的后缀上。
     *
     * [例]839647521是1--9的排列。1—9的排列最前面的是123456789，最后面的987654321，
     * 从右向左扫描若都是增的，就到了987654321，也就没有下一个了。否则找出第一次出现下降的位置。
     *
     * 【例】 如何得到346987521的下一个
     * 1，从尾部往前找第一个P(i-1) < P(i)的位置
     * 3 4 6 <- 9 <- 8 <- 7 <- 5 <- 2 <- 1
     * 最终找到6是第一个变小的数字，记录下6的位置i-1
     *
     * 2，从i位置往后找到最后一个大于6的数
     * 3 4 6 -> 9 -> 8 -> 7 5 2 1
     * 最终找到7的位置，记录位置为m
     *
     * 3，交换位置i-1和m的值
     * 3 4 7 9 8 6 5 2 1
     *
     * 4，倒序i位置后的所有数据
     * 3 4 7 1 2 5 6 8 9
     * 则347125689为346987521的下一个排列
     * 
*/