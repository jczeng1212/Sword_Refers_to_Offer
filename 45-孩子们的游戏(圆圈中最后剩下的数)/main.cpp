class Solution {
public:
    int LastRemaining_Solution(int n, int m){
        
    }
};



//链接：https://www.nowcoder.com/questionTerminal/f78a359491e64a50bce2d89cff857eb6?f=discussion
//来源：牛客网
//用数组来模拟约瑟夫环的过程
//假定元素是从0~n-1，那么刚开始第一步的时候，i为0，step为1
class Solution {
public:
    int LastRemaining_Solution(int n, int m){
        if (n < 1 || m < 1) 
            return -1;
        int array[1000] = {0};   //记录哪些元素已被删除
        int i = -1;
        int step = 0;   //进行计步
        int count = n;  //记录环中剩余元素数，初始为n

        while (count > 0) {
            i++;        //指向被删除元素的下一个元素
            if (i == n)  //模拟循环操作
                i = 0;
            
            if (array[i] == -1)
                continue;
            
            step++;

            if (step == m) {    //找到了待删除的元素
                array[i] = -1;
                step = 0;
                count--;
            }
        }

        return i;   //返回跳出循环时的i,即最后一个被设置为-1的元素
    }
};
