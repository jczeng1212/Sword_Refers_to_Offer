#include<string>
using namespace std;


//用replace函数
class Solution {
public:
	void replaceSpace(char *str,int length) {
        //str.replace(pos, len, str2)

        string str2 = "%20";
        //string str1 = str;
        string str1(str);

        for( int i = 0; i < length; i++){
            if( str1[i] == ' ' ){
                str1.replace(i, 1, str2);
            }
        }

        auto ret=str1.c_str();
        strcpy(str,ret);


	}
};


//链接：https://www.nowcoder.com/questionTerminal/4060ac7e3e404ad1a894ef3e17650423?f=discussion
//来源：牛客网
//即剑指offer解法
/*注意：
1. '\0'为字符串结束标志

*/
class Solution {
public:
void replaceSpace(char *str,int length) {
        //遍历一边字符串找出空格的数量
        if( str == NULL || length < 0 )
            return ;
        
        int i = 0;
        int oldnumber = 0;  //记录以前字符串的长度，包括最后一位字符串结束标志'\0'
        int replacenumber = 0;  //记录空格的数量
        while( str[i] != '\0' ){
            oldnumber++;
            if( str[i] == ' ' ){
                replacenumber++;
            }
            i++; 
        }
        
        int newlength = oldnumber + replacenumber * 2;  //插入后的长度
        if( newlength > length )    //如果计算后的长度大于总长度就无法插入
            return ;
        
        int pOldlength = oldnumber; //注意不要减一因为隐藏个‘\0’也要算里
        int pNewlength = newlength;
        
        while( pOldlength >= 0 && pNewlength > pOldlength ){ //放字符
            if( str[pOldlength] == ' ' ){ //碰到空格就替换    
                str[pNewlength--]='0';
                str[pNewlength--]='2';
                str[pNewlength--]='%';    
            }else{  //不是空格就把pOldlength指向的字符装入pNewlength指向的位置
                str[pNewlength--] = str[pOldlength];   
            }
            pOldlength--; //不管是if还是else都要把pOldlength前移    
        }//while
    }
};