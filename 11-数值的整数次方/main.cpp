#include<iostream>
using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        double result = 1.0;
        while( exponent ){
            result *= base;
            exponent--;
        }

        return result;
    }
};


//图画的非常好
//这个题的难点在于把所有情况都理清楚，并且做到非常的直观。
//链接：https://www.nowcoder.com/questionTerminal/1a834e5e3e1a4b7ba251417554e07c00?f=discussion
//来源：牛客网
class Solution {
    double power(double base, int exp) {
        if (exp == 1) return base;
        if ((exp & 1) == 0) {   //二进制下，1110与0001为0，前者为偶数
            int tmp = power(base, exp >> 1);    //exp右移1位，表示除2
            return tmp * tmp;
        } else {
            int tmp = power(base, (exp - 1) >> 1);  //将exp-1除以2
            return tmp * tmp * base;
        }
    }
public:
    double Power(double base, int exp) {
        if (base == 0) {
            if (exp > 0) return 0;
            else if (exp == 0) return 0;
            else throw invalid_argument("Invalid input!");
        } else {
            if (exp > 0) return power(base, exp);
            else if (exp == 0) return 1;
            else return 1 / power(base, -exp);
        }
    }
};



//链接：https://www.nowcoder.com/questionTerminal/1a834e5e3e1a4b7ba251417554e07c00?f=discussion
//来源：牛客网

/**
 * 1.全面考察指数的正负、底数是否为零等情况。
 * 2.写出指数的二进制表达，例如13表达为二进制1101。
 * 3.举例:10^1101 = 10^0001*10^0100*10^1000。
 * 4.通过&1和>>1来逐位读取1101，为1时将该位代表的乘数累乘到最终结果。
 */
public double Power(double base, int n) {
    double res = 1,curr = base;
    int exponent;
    if(n>0){
        exponent = n;
    }else if(n<0){
        if(base==0)
            throw new RuntimeException("分母不能为0"); 
        exponent = -n;
    }else{// n==0
        return 1;// 0的0次方
    }
    while(exponent!=0){
        if((exponent&1)==1)
            res*=curr;
        curr*=curr;// 翻倍
        exponent>>=1;// 右移一位
    }
    return n>=0?res:(1/res);       
}




double division(int a, int b)
{
   if( b == 0 )
   {
      throw "Division by zero condition!";
   }
   return (a/b);
}

int main ()
{
   int x = 50;
   int y = 0;
   double z = 0;
 
   try {
     z = division(x, y);
     //cout << z << endl;
   }catch (const char* msg) {
     cerr << msg << endl;
   }
 
   return 0;
}