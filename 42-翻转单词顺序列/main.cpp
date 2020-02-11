#include<string>
#include<algorithm>
#include<iostream>
using namespace std;


//【无法通过，不知道原因。。】
//1.将整体翻转一遍
//2.针对每个单词进行一次翻转
//设置方法ReversePart进行翻转操作
class Solution {
public:
    string ReverseSentence(string str) {
        if ( str.empty() )
            return str;
        string str1 = ReversePart(str, 0, str.size() - 1);
        //cout << str1 << "  test" << endl;
        int index = 0;
        int start = 0;
        int end = 0;
        while ( end != (str1.size() - 1) ) {
            while(end < str.size() && str[end] == ' ' ) //将字符串前面的空格跳过
               end++;
            start = end;
            if ( isspace( str1[end] ) ){     //为空格的时候 
                str1 = ReversePart(str1, start, end - 1);
                //cout << str1 << " -" << endl;
                start = end + 1;
            }else{      //不为空格的时候
                end++;
            }
        }

        cout << str1 << endl;
        return str1;

    }

private:
    string ReversePart(string str, int start, int end){
        for (int i = start, j = end ; i < j; i++, j--) {
            swap(str[i], str[j]);
        }
        return str;
    }

};


//链接：https://www.nowcoder.com/questionTerminal/3194a4f4cf814f63919d0790578d51f3?f=discussion
//来源：牛客网
//翻转str从s到e的部分
//细节很重要，要特别考虑到“   ”等输入中包含多余空格的情形
class Solution {
public:
    void ReverseWord(string &str, int s, int e){
        while(s < e)
            swap(str[s++], str[e--]);
    }
 
    string ReverseSentence(string str) {
        ReverseWord(str, 0, str.size() - 1); //先整体翻转
        int s = 0, e = 0;
        int i = 0;
        while(i < str.size())
        {
            while(i < str.size() && str[i] == ' ') //将字符串前面的空格跳过
               i++;
            e = s = i; //记录单词的第一个字符的位置
            while(i < str.size() && str[i] != ' ') //不是空格 找单词最后一个字符的位置
            {
                i++;
                e++;
            }
            ReverseWord(str, s, e - 1); //局部翻转
        }
        return str;
    }
};


int main(){
    Solution solution;
    
    solution.ReverseSentence("I am a student.");

    return 0;
}