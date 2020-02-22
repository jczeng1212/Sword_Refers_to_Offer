#include<iostream>
using namespace std;

//暴力做法
//输入数字n，n有O(logn)位
//时间复杂度：O(n * logn)
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int number = 0;
        for (int i = 1; i <= n; i++) {  //统计小于n的所有数中有多少个1
            number += NumberOf1(i);
        }

        return number;
    }

private:
    int NumberOf1(int n){
        int number = 0;
        while(n) {
            if(n % 10 == 1) //每次检查个位是否为1. 不能使用n&1==1来进行判断，n中最右位为1，不代表n的个位中有1
                number++;
            n = n / 10; //不能用 n = n >> 1，因为这是除以2
            
        }

        return number;
    }
}; 



//链接：https://www.nowcoder.com/questionTerminal/bd7f978302044eee894445e244c7eee6?f=discussion
//来源：牛客网
//这个讲的比较清楚：https://www.cnblogs.com/xuanxufeng/p/6854105.html
//主要思路：设定整数点（如1、10、100等等）作为位置点i（对应n的个位、十位、百位等等），分别对每个数位上有多少包含1的点进行分析
//根据设定的整数位置，对n进行分割，分为两部分，高位n/i，低位n%i
//当i表示百位，且百位对应的数>=2,如n=31456,i=100，则a=314,b=56，此时百位为1的次数有a/10+1=32（最高两位0~31），每一次都包含100个连续的点，即共有(a%10+1)*100个点的百位为1
//当i表示百位，且百位对应的数为1，如n=31156,i=100，则a=311,b=56，此时百位对应的就是1，则共有a%10(最高两位0-30)次是包含100个连续点，当最高两位为31（即a=311），本次只对应局部点00~56，共b+1次，所有点加起来共有（a%10*100）+(b+1)，这些点百位对应为1
//当i表示百位，且百位对应的数为0,如n=31056,i=100，则a=310,b=56，此时百位为1的次数有a/10=31（最高两位0~30）
//综合以上三种情况，当百位对应0或>=2时，有(a+8)/10次包含所有100个点，还有当百位为1(a%10==1)，需要增加局部点b+1
//之所以补8，是因为当百位为0，则a/10==(a+8)/10，当百位>=2，补8会产生进位位，效果等同于(a/10+1)

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n){
        int count = 0;
        long long i = 1;
        for (i = 1; i <= n; i *= 10) {
            //i表示当前分析的是哪一个数位
            int a = n / i;  //
            int b = n % i;
            count = count + (a+8)/10*i + (a%10==1)*(b+1);
        }
        return count;
        }
};




int main(){
    int abc = 3 & 1;
    cout << abc << endl;

}