#include<string>
#include<iostream>
using namespace std;

class Solution1 {
public:
    bool match(char* str, char* pattern)
    {
        cout << *(str+1) << endl;
        return true;
    }
};

//【递归方法】
//链接：https://www.nowcoder.com/questionTerminal/45327ae22b7b413ea21df13ee7d6429c?f=discussion
//来源：牛客网
class Solution2 {
public:
    bool match(char* str, char* pattern) {
        if( str == NULL || pattern == NULL )
            return false;
        return matchCore(str, pattern);
    }
    
    bool matchCore(char* str, char* pattern) {
        if ( *str == '\0' && *pattern == '\0' )
            return true;
        if ( *str != '\0' && *pattern == '\0' )
            return false;
        if ( *(pattern+1) == '*' ) {
            if ( *pattern == *str || ( *pattern == '.' && *str != '\0' ) )
                /*
                matchCore(str,pattern+2):模式串未匹配
                matchCore(str+1,pattern):模式串已经匹配成功，尝试匹配下一个字符串
                matchCore(str+1,pat+2)：模式串已经成功匹配，并且不匹配下一个字符串内容  注意这里 matchCore(str+1,pat+2)重复考虑了（代码中已经去除），谢谢@chlq的指出 */
                return matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
            else
                return matchCore(str, pattern + 2);
        }
        if( *str == *pattern || ( *pattern == '.' && *str != '\0' ) )
            return matchCore(str + 1, pattern + 1);
        return false;
    }
};



/*
【动态规划】本解法来自牛客网，但在牛客网网上无法获取str和pattern的长度，
修改后在leetcode(https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/)和leetcode(https://leetcode-cn.com/problems/regular-expression-matching/)上通过。
链接：https://www.nowcoder.com/questionTerminal/45327ae22b7b413ea21df13ee7d6429c?f=discussion
来源：牛客网
dp[i][j] 表示 s 的前 i 个是否能被 p 的前 j 个匹配
如果 pattern[j] == str[i] || pattern[j] == '.', 此时dp[i][j] = dp[i-1][j-1];
如果 pattern[j] == '*'
    分两种情况:
    1: 如果pattern[j-1] != str[i] && pattern[j-1] != '.', 此时dp[i][j] = dp[i][j-2] //a*匹配0次
    2: 如果pattern[j-1] == str[i] || pattern[j-1] == '.'
        此时dp[i][j] = dp[i][j-2] // a*匹配0次
        或者 dp[i][j] = dp[i][j-1] // a*匹配1次
        或者 dp[i][j] = dp[i-1][j] // a*匹配多次
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        if( s.empty() || p.empty() )
            return false;
        
        bool dp[ s.length() + 1 ][ p.length() + 1 ];
        dp[0][0] = true;
        if (p[1] == '*')
            dp[0][1] = true;
        for (int i = 2; i < p.length(); i ++) { //当字符串为空，模式串为
            if( p[i - 1] == '*' )
                dp[0][i] = dp[0][i - 2];
        }

        for (int i = 1; i < s.length(); i ++) {
            for (int j = 1; j < p.length(); j ++) {
                if( p[j] == '.' || p[j] == s[i] )
                    dp[i][j] = dp[i - 1][j - 1];
                else if( p[j] == '*' ) {
                    if( p[j - 1] != s[i] && p[j - 1] != '.') 
                        dp[i][j] = dp[i][j - 2];    //dp[i][j - 2]说明s 的前 i 个是否能被 p 的前 j-2 个匹配, 此时p的第j-1和第j个字符都没有效，起不到匹配的作用，故dp[i][j] = dp[i][j - 2]
                    else 
                        dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j];
                }
            }
        }
        return dp[ s.length() ][ p.length() ];

    }
};






int main(){
    Solution solution;
    char str[] = "aaaaafafafaa";
    char pattern[] = ".*a";
    solution.match(str, pattern);

    


    
    
    //cout << sizeof(str) << endl;
    //solution.match(str, pattern);

    return 0;
}