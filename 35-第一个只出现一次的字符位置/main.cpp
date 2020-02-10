#include<iostream>
#include<string>
#include<map>
using namespace std;

//暴力法：
//首先设置一个int count[52]的数组，该数组的下标表示某个字母，同时每遇到一个新的字母，才创建对应的下标。
//遍历该字符串，

class Solution1 {
public:
    int FirstNotRepeatingChar(string str) {
        
    }
};


//字母包含大小写总共有:26*2个，而总共有10001个位置，故必有大量字母重复
//只出现一次是全局信息
//使用异或运算符^，将重复字符消去，同时设置flag标记重复字符。最后对所有剩余字符进行遍历，第一个出现不带flag的即为所找的。
//字符怎么消去？如何对字符进行异或处理？答：A-Z的ASCII为：65-90，a-z的ASCII为：97-122。在进行异或前进行强制转化为int型，(int)a
//map如何使用？

//【利用map实现】
//链接：https://www.nowcoder.com/questionTerminal/1c82e8cf713b4bbeb2a5b31cf5b0417c?f=discussion
//来源：牛客网
//讨论：
//因为map是以红黑树实现的，map后，不能以map的迭代器遍历，必需用str[i]来遍历。你的方法很好
//map是自动排序的，但是上述程序中map只是用来统计字符串str中每个字符出现的次数，最后一个遍历时遍历的是字符串str(而不是map中的first成员 (char类型) )，str中的各字符的原始顺序并没有改变，所以输出的是题目所要求的的第一次只出现一次的字符。
class Solution2 {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> mp;
        for(int i = 0; i < str.size(); ++i)
            mp[str[i]]++;
        for(int i = 0; i < str.size(); ++i){
            if(mp[str[i]]==1)
                return i;
        }
        return -1;
    }
};

//【hash法】主要涉及ASCII编码问题
//没有100%通过
//链接：https://www.nowcoder.com/questionTerminal/1c82e8cf713b4bbeb2a5b31cf5b0417c?f=discussion
//来源：牛客网
//利用每个字母的ASCII码作hash来作为数组的index。
//首先用一个58长度的数组来存储每个字母出现的次数，为什么是58呢，主要是由于A-Z对应的ASCII码为65-90，a-z对应的ASCII码值为97-122，而每个字母的index=int(word)-65，比如g=103-65=38，而数组中具体记录的内容是该字母出现的次数，最终遍历一遍字符串，找出第一个数组内容为1的字母就可以了，时间复杂度为O(n)
//ASCII码中的90-96不是字母 但是为了统一减65来计算 所以要再加上6个长度 不然就要判断是否是小写字母 小写字母要减65再减6
//从65开始到122结束(小a到大z，算上了几个没用的字符)一共有58位，创建一个数组不可能从游标65开始吧？都是从零开始的，所以如果游标要跟字符对应上的话字符就要减65。

class Solution{
public:
    int FirstNotRepeatingChar(string str) {
        int words[58];
        for( int i = 0; i < str.size(); i++){
            words[ ( (int)str[i] ) - 65 ] += 1;
        }

        for( int i = 0; i < str.size(); i++){
            //cout << words[i] << endl;
            if( words[ ( (int)str[i] ) - 65 ] == 1 ){
                cout << words[i] << endl;
                //cout << str[i] << endl;
                return i;
            }
                
        }
        return -1;
    }
};











int main(){
    /*
    char a = 'a';
    char z = 'z';
    char A = 'A';
    char Z = 'Z';
    int aba;
    cout << (int)a << endl;
    cout << (int)z << endl;
    cout << (int)A << endl;
    cout << (int)Z << endl;
    aba = (int)(a) ^ (int)(z);
    cout << aba << endl;
    */

    string abc = "googgle";
    Solution solution;
    solution.FirstNotRepeatingChar(abc);
}