#include<string>
#include<vector>
#include<iostream>
using namespace std;

//【无法通过，超时】
//设置一个vector保存左移的部分
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if ( str.empty() || n == 0 ){
            return str;
        }

        vector<char> temp;
        int temp_index = n;
        for (int i = 0; i < str.size() - n; i++) {
            if( temp_index ){
                temp.push_back( str[i] );
                //cout << str[i] << endl;
                temp_index--;
            }
            str[i] = str[ i + n ];
            //cout << str[i+n] << endl;
        }
        
        //cout << str << endl;


        //m用来指示temp的下标
        //i指示原字符串str的下标
        for (int i = str.size() - n, m =0; i <= str.size() - 1 ; i++ , m++) {
            str[i] = temp[m];
        }

        return str;
    }
};


//链接：https://www.nowcoder.com/questionTerminal/12d959b108cb42b1ab72cef4d36af5ec?f=discussion
//来源：牛客网
//字符串拷贝两次：abc=>abcabc
//str.substr(n, len)
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.length();
        if(len == 0) return "";
        n = n % len;
        str += str;
        return str.substr(n, len);
    }
};


//链接：https://www.nowcoder.com/questionTerminal/12d959b108cb42b1ab72cef4d36af5ec?f=discussion
//来源：牛客网
//原理：YX = (XTYT)T
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.size();
        if(len == 0) return str;
        n %= len;
        for(int i = 0, j = n - 1; i < j; ++i, --j) swap(str[i], str[j]);
        for(int i = n, j = len - 1; i < j; ++i, --j) swap(str[i], str[j]);
        for(int i = 0, j = len - 1; i < j; ++i, --j) swap(str[i], str[j]);
        return str;
    }
};


//链接：https://www.nowcoder.com/questionTerminal/12d959b108cb42b1ab72cef4d36af5ec?f=discussion
//来源：牛客网
//按照剑指offer书上的方法，两次翻转字符串。原理同上，只不过先对整体进行翻转，再在内部进行翻转
class Solution {
public:
    string LeftRotateString(string str, int n) {
        reverse(str.begin(), str.end());
        reverse(str.begin(), str.begin() + str.size() - n);
        reverse(str.begin() + str.size() - n, str.end());
        return str;
    }
};



int main(){
    Solution solution;
    cout << solution.LeftRotateString("abcXYZdef", 3).size() << endl;

    return 0;
}