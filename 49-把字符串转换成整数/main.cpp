#include<string>
#include<iostream>
using namespace std;

//【我的做法】
/*[出现原因]出现这个测试用例通过不了的原因是因为sum用int类型，应该换为long long类型
case通过率为85.71%=>现已通过
用例:-2147483649
对应输出应该为:0
你的输出为:2147483647
*/
//数字字母符号
//数字：0-9
//字母：a-zA-Z
//符号：'+','-'
class Solution {
public:
    int StrToInt(string str) {
        if ( str.empty() ){
            return 0;
        }
        long long sum = 0;
        int weight = 1;
        for (int i = str.size() - 1; i >= 0; i--) { 
            if( isalpha( str[i] ) ) {
                //cout << "yes alpha" << endl;
                return 0;
            }
            if ( i == 0 ){   //单独处理str中的第一个字符后面
                if ( str[i] == '+' ){
                    break;
                } else if ( str[i] == '-' ) {
                    sum = -sum;
                    break;
                }
            }
            sum += (int)(str[i] - '0') * weight;
            cout << "sum " << sum << endl;
            weight *= 10;
        }

        if(sum >= -2147483648 && sum <= 2147483647){ //int [-2^31,2^31-1]
            return sum;
        }else{
            return 0;
        }
        
    }
};


//链接：https://www.nowcoder.com/questionTerminal/1277c681251b4372bdef344468e4f26e?f=discussion
//来源：牛客网
class Solution1 {
public:
    int StrToInt(string str) {
        int n = str.size(), s = 1;
        long long res = 0;
        if(!n) return 0;
        if(str[0] == '-') s = -1;
        for(int i = (str[0] ==  '-' || str[0] == '+') ? 1 : 0; i < n; ++i){ //如果字符串第一位是'-'/'+'，那么就从第二位开始
            if( !('0' <= str[i] && str[i] <= '9') ) return 0;
            res = (res << 1) + (res << 3) + (str[i] & 0x0f); //res=res*10+str[i]-'0';利用位运算提高计算效率 
            //和res=res*10+str[i]-'0'是一样的。左移是乘以2的次方。(res << 1) + (res << 3) = res * 2 + res * 8 = res * 10 。 
            //字符'0'到'9'的ascii值的后四位刚好就是0到9的二进制表示，所以str[i]&0xf等于str[i]-'0'。 位运算会比乘法运算效率高那么一点
            //针对字符0-9的，0-9的ascii码值为0x30，0x31，0x32 0x33 ...0x39，因此与0x0f按位与后只保留个位上的数即0x0，0x1，。。。0x9
        } 
        //作者：Leo201904232141453
        //链接：https://www.nowcoder.com/questionTerminal/1277c681251b4372bdef344468e4f26e?f=discussion
        //最好加一个溢出判断：
        if(res*s >= -2147483648 && res*s <= 2147483647){ //int [-2^31,2^31-1]
            return res*s;
        }else{
            return 0;
        }

        return res * s;
    }
};


//链接：https://www.nowcoder.com/questionTerminal/1277c681251b4372bdef344468e4f26e?f=discussion
//来源：牛客网
class Solution2 {
public:
    int StrToInt(string str) {
        long long ret = 0;
        int sz = str.size();
        bool flag = false;
        for (int i = 0; i < sz ; ++i) {
            if ( str[i] >= '0' && str[i] <= '9' ) {
                ret = ret*10 + (str[i] - '0');               
            } else if ( str[i] == '-' && i == 0 ) {
                flag = true;
            } else if ( ( str[i] < '0' || str[i] > '9' ) && i != 0 )
                return 0;
        }
        if ( flag ) 
            ret = -ret;
        return ret;
    }
};




int main(){
    //Solution solution;
    //cout << solution.StrToInt("+123") << endl;
    //bool a  = (('1' - '0') == 1);
    //cout << a << endl;
    //char a = '1';
    //int b = a & 0x0f;
    cout << 0x09 << endl;

    return 0;
}