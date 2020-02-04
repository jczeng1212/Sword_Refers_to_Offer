#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//以下想法错误
//状态：dp[i][j]：首先，应该是二维的状态数组，表示从第i位到第j位的连续子数组的最大和
//状态方程：
/*
if array[j] > 0:
    dp[i][j] = dp[i][j-1] + array[j];
else:
    dp[i][j] = dp[i][j-1];

*/



/*
链接：https://www.nowcoder.com/questionTerminal/459bd355da1549fa8a49e350bf3df484?f=discussion
来源：牛客网

动态规划初级题目,做完之后,可以试试最大子矩阵和(https://www.nowcoder.com/questionTerminal/a5a0b05f0505406ca837a3a76a5419b3)
该题目思路:
dp[i]表示以元素array[i]结尾的最大连续子数组和.
以[-2,-3,4,-1,-2,1,5,-3]为例
可以发现,
dp[0] = -2
dp[1] = -3
dp[2] = 4
dp[3] = 3
以此类推,会发现
dp[i] = max(dp[i-1]+array[i],array[i]).
*/
//时间复杂度：O(n)
//空间复杂度：O(n)

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if( array.empty() )
            return 0;
        
        int dp[1000];
        dp[0] = array[0];
        int maxtemp = dp[0];
        for( int i=1; i<array.size(); i++ ){
            dp[i] = max(dp[i-1] + array[i], array[i]);
            if(dp[i] > maxtemp){
                maxtemp = dp[i];
            }
        }
        return maxtemp;    
    }
};


//下面是一个优化空间复杂度的方法
//dp[i] = max(dp[i-1]+array[i],array[i]) => dp = max(dp+array[i],array[i])
/*
可参考：
链接：https://www.nowcoder.com/questionTerminal/459bd355da1549fa8a49e350bf3df484?f=discussion
来源：牛客网

使用动态规划
F（i）：以array[i]为末尾元素的子数组的和的最大值，子数组的元素的相对位置不变
F（i）=max（F（i-1）+array[i] ， array[i]）
res：所有子数组的和的最大值
res=max（res，F（i））

*/
//时间复杂度：O(n)
//空间复杂度：O(n)

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if( array.empty() )
            return 0;
        
        int dp;
        dp = array[0];
        int maxtemp = dp;
        for( int i=1; i<array.size(); i++ ){
            dp = max(dp + array[i], array[i]);
            if(dp > maxtemp){
                maxtemp = dp;
            }
        }
        return maxtemp;    
    }
};