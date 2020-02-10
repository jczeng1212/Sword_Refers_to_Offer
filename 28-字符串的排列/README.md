# **28-字符串的排列**

牛客网链接：[28-字符串的排列](https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=11180&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

题目描述

> 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

输入描述

> 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。



## 1.一刷情况

**日期**：2020.02.

**Code**：

```c++

```

**掌握情况**：完全不会/会一半/完全会

**存在问题**：





## 参考Code

### Code1 

**日期**：2020.02.09

**方法**：递归方法。将每个位置上的字符与后面的字符进行排序。

**时间复杂度**：

**具体思路**：https://www.cnblogs.com/cxjchen/p/3932949.html，

**Code**：

```c++
见main.cpp
```

作者：pt
链接：https://www.nowcoder.com/questionTerminal/fe6b651b66ae47d7acce78ffdd9a96c7?f=discussion
来源：牛客网

第二个swap的作用：第二个swap用以使得字符数组的顺序回到进入递归前的状态，这样才不会影响外部的遍历顺序。因为在第一次交换后进入递归运算的时候，字符数组的顺序改变了，例如“abc”， i = 0时对应‘a’，j = 1时对应 'b'，进行一次交换，此时的字符数组的顺序为 "bac"，从递归返回时，顺序依然是“bac”，则进行第二次交换使得 “bac” -> “abc”，这样在后续才可以进行'a'与'c'的交换，不会落下某一种情况。





### Code2 

**日期**：2020.02.09

**方法**：字典序排列的方法。尚未完全搞懂。

**时间复杂度**：

**具体思路**：

**Code**：

```c++

```

