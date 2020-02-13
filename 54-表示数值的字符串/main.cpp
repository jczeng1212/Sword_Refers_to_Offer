#include<string.h>
using namespace std;

//【我的第一次解法】
/*
存在于有效十进制数字中的字符：
数字：0-9
正负号：+/-
指数：e/E
小数点：.

对于一些特殊数字中的要求：
指数：只能为e/E，e/E后面不能为空，不能为小数，前面必须要有数字
一般数字不能含有其他字母
小数只能有一个小数点
正负号只能有一个

将数字按整数、小数和指数分类
分别实现两个私有函数isDecimal()和isExponent()，用来进一步判断小数和指数的正确性
遍历字符串，
    若遇到小数点，则转入isDecimal()函数进一步判断字符串后面的是否满足；
    若遇到e/E，则转入isExponent()函数进一步判断字符串后面的是否满足;
    若都没有遇到，则判定为一个整数

*/
class Solution {
public:
    bool isNumeric(char* string) {
        if ( !string ) {
            return false;
        }

        while( !string ){
            if( *string == '.' ){
                return isDecimal(string+1);
            }
            if( *string == '*' ){
                return isExponent(string+1);
            }
        }
        
    }

private:
    bool isDecimal(char* string){
        while( !string ){
            if( *string == '.' ){   //说明有多个小数点
                return false;
            }
        
        }//while
    }

    bool isExponent(char* string){

    }

};


//链接：https://www.nowcoder.com/questionTerminal/6f8c901d091949a5837e24bb82a731f2?f=discussion
//来源：牛客网
class Solution {
public:
    bool isNumeric(char* str) {
        if (str == NULL) 
            return false;

        // 标记符号、小数点、e是否出现过
        bool sign = false, decimal = false, hasE = false;
        
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == 'e' || str[i] == 'E') {
                if (i == strlen(str)-1) return false; // e后面一定要接数字，这里检测e/E是不是最后一位
                if (hasE) return false;  // 不能同时存在两个e
                hasE = true;
            } else if (str[i] == '+' || str[i] == '-') {
                // 第二次出现+-符号，则必须紧接在e之后
                if (sign && str[i-1] != 'e' && str[i-1] != 'E') return false;
                // 第一次出现+-符号，且不是在字符串开头，则也必须紧接在e之后
                if (!sign && i > 0 && str[i-1] != 'e' && str[i-1] != 'E') return false;
                sign = true;
            } else if (str[i] == '.') {
              // e后面不能接小数点，小数点不能出现两次
                if (hasE || decimal) return false;
                decimal = true;
            } else if (str[i] < '0' || str[i] > '9') // 不合法字符
                return false;
        }
        return true;
    }
};


//作者：不做菜鸡
//链接：https://www.nowcoder.com/questionTerminal/6f8c901d091949a5837e24bb82a731f2?f=discussion
//来源：牛客网
//上面的改进版，更加完整
class Solution {
public:
    bool isNumeric(char* str)
    {
        if(str == nullptr)  return false;
        
        int sign = false, deciminal = false, hasE = false;  //'+''-'符号、小数点和指数符号出现标志
        for(int i = 0; i < strlen(str); i++)
        {
            if(str[i] == 'e' || str[i] == 'E')
            {
                if(i == 0)  return false;  //指数符号前必须有整数
                if(i == strlen(str) - 1)  return false;  //指数符号后必须有整数
                if(hasE)  return false;  //只能有一个指数符号
                hasE = true;
            }
            else if(str[i] == '.')
            {
                if(hasE)  return false;  //小数点只能出现在指数符号之前
                if(i == strlen(str) - 1)  return false;  //小数点不能出现在最后一位上
                if(deciminal)  return false;  //小数点只能出现一次
                deciminal = true;
            }
            else if(str[i] == '+' || str[i] == '-')
            {
                //第一次出现+''-'符号只能在第一个字符或者指数符号后
                if(!sign && i != 0 && !hasE)  return false;  
                if(sign && !hasE)  return false;  //第二出现'+''-'符号只能在指数符号后
                if(i == strlen(str) - 1)  return false;  //'+''-'符号不能出现在最后一位上
                sign = true;
            }
            else if(str[i] < '0' || str[i] > '9')  return false;  //其它的非数字字符
        }
        return true;
    }
};