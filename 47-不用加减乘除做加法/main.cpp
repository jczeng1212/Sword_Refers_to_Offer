
//写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。



//把各位的值和进位的值分开计算，计算出来后再加到一起(这个加到一起的过程也是各位的值和进位的值分开)
//各位的值需要相加，二进制每位相加相当于各位做异或操作
//进位的值的计算，二进制各位做与操作的结果，再向左移一位
//链接：https://www.nowcoder.com/questionTerminal/59ac416b4b944300b617d4f7f111b215?f=discussion
//来源：牛客网
/*
首先看十进制是如何做的： 5+7=12，三步走
第一步：相加各位的值，不算进位，得到2。
第二步：计算进位值，得到10. 如果这一步的进位值为0，那么第一步得到的值就是最终结果。
第三步：重复上述两步，只是相加的值变成上述两步的得到的结果2和10，得到12，但是进位为0, 跳出循环

同样我们可以用三步走的方式计算二进制值相加： 5-101，7-111 
第一步：相加各位的值，不算进位，得到010，二进制每位相加就相当于各位做异或操作，101^111。

第二步：计算进位值，得到1010，相当于各位做与操作得到101，再向左移一位得到1010，(101&111)<<1。

第三步重复上述两步， 各位相加 010^1010=1000，进位值为100=(010&1010)<<1。
     继续重复上述两步：1000^100 = 1100，进位值为0，跳出循环，1100为最终结果。

*/
class Solution {
public:
    int Add(int num1, int num2) {
        while (num2 != 0) { //当进位为0，跳出循环
            int temp = num1 ^ num2; //计算各位的值，二进制每位相加相当于各位做异或操作
            num2 = (num1 & num2) << 1;  //计算进位的值，把各位进行与操作并向左移一位
            num1 = temp;
        }

        return num1;
    }
};