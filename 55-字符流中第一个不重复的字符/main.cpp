#include<string>
#include<queue>
#include<map>
using namespace std;

class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
         
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce(){
        string str;

    }

};


//链接：https://www.nowcoder.com/questionTerminal/00de97733b8e4f97a3fb5c680ee10720?f=discussion
//来源：牛客网
/*
提供一个高效的算法：
思路：时间复杂度O（1），空间复杂度O（n）
        1、用一个128大小的数组统计每个字符出现的次数
        2、用一个队列，如果第一次遇到ch字符，则插入队列；其他情况不在插入
        3、求解第一个出现的字符，判断队首元素是否只出现一次，如果是直接返回，否则删除继续第3步骤

分析：可以看出相同的字符只被插入一次，最多push128个，同时大多数情况会直接返回队首。所以大家不要被里面的while循环迷惑

'\0'的ASCII码为0，'0'的ASCII码为48
*/
class Solution{
public:
  //Insert one char from stringstream
    void Insert(char ch) {
        ++cnt[ch - '\0'];
        if(cnt[ch - '\0'] == 1)
           data.push(ch);
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        while (!data.empty() && cnt[data.front()] >= 2) {
            data.pop();
        }
        if (data.empty())
            return '#';
        
        return data.front();
    }
    Solution() {
      memset(cnt, 0, sizeof(cnt));    
    }

private:
    queue<char> data;
    unsigned cnt[128];
};


//链接：https://www.nowcoder.com/questionTerminal/00de97733b8e4f97a3fb5c680ee10720?f=discussion
//来源：牛客网

class Solution
{
public:
  //Insert one char from stringstream
    string s;
    char hash[128]={0}; //字符在计算机中以ASCII码的形式存储，当字符作为数组下标时，其表示的下标值为该字符的ASCII码的十进制值。而ASCII码由8位表示，只有后面7位起作用，2^7为128，因此ASCII码共有128个字符，十进制范围为0~127.
    void Insert(char ch)
    {
        s+=ch;
        hash[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
         
        int size = s.size();
        for (int i = 0; i < size; ++i)
        {
            if(hash[s[i]] == 1)
                return s[i];
        }
        return '#';
    }
 
};


//作者：喜欢ctrl的cxk
//链接：https://www.nowcoder.com/questionTerminal/00de97733b8e4f97a3fb5c680ee10720?f=discussion
//来源：牛客网

class Solution
{
public:
  //Insert one char from stringstream
    string str;
    map<char,int> m;    //用map来记录字符出现的次数
    void Insert(char ch)
    {
        str += ch;
        m[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(auto it : str)
        {
            if(m[it] == 1)
            {
                return it;
            }
        }
        return '#';
    }

};