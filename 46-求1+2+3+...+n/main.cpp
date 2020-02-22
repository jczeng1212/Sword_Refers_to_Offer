
//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
//sum(n) = n + sum(n-1)

class Solution {
public:
    int Sum_Solution(int n) {
        if (n == 1) {
            return 1;
        } else {
            return n + Sum_Solution(n - 1);
        }
    }
};

//链接：https://www.nowcoder.com/questionTerminal/7a0da8fc483247ff8800059e12d7caf1?f=discussion
//来源：牛客网
//利用递归代替了循环，使用逻辑与运算&&判断n何时为0，并利用了其短路性质(前面为假，后面不计算)
class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1));
        return ans;
    }
};

//在上面的基础上简化而来
class Solution {
public:
    int Sum_Solution(int n) {
        n && (n += Sum_Solution(n - 1));
        return n;
    }
};


//一个Python的写法
/*
链接：https://www.nowcoder.com/questionTerminal/7a0da8fc483247ff8800059e12d7caf1?f=discussion
来源：牛客网
//在Python 中，and 和 or 执行布尔逻辑演算，但是它们并不返回布尔值，而是返回它们实际进行比较的值之一
//从左到右扫描，
//运算结果为假，则返回第一个为假的表达式值，
//运算结果为真，则返回最后一个表达式值。
# -*- coding:utf-8 -*-
class Solution:
    def Sum_Solution(self, n):
        return n and (n + self.Sum_Solution(n - 1))

*/
