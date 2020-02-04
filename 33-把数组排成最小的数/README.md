# 33-把数组排成最小的数

牛客网链接：[33-把数组排成最小的数](https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&tqId=11185&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

题目描述

> 描述内容



## 1.一刷情况

**日期**：2020.02.03

**Code**：

```c++

```

**掌握情况**：完全不会

**存在问题**：





## 参考Code

### Code1 

**日期**：2020.02.03

**方法**：简明扼要说明方法是什么，用了什么数据结构等等。

**时间复杂度**：

**具体思路**：

**Code**：

```c++
//这里需要熟悉c++中 sort函数的具体用法
//链接：https://www.nowcoder.com/questionTerminal/8fecd3f8ba334add803bf2a06af1b993?f=discussion
//来源：牛客网

/*对vector容器内的数据进行排序，按照 将a和b转为string后
 若 a＋b<b+a  a排在在前 的规则排序,
 如 2 21 因为 212 < 221 所以 排序后为 21 2 
  to_string() 可以将int 转化为string
*/ 
class Solution {
 public:
     static bool cmp(int a,int b){
         string A = ""; //ab
         string B = ""; //ba
         A += to_string(a);
         A += to_string(b);
         B += to_string(b);
         B += to_string(a);
          
         return A < B;
     }
     string PrintMinNumber(vector<int> numbers) {
         string  answer = "";
         sort(numbers.begin(), numbers.end(), cmp);
         for( int i = 0; i < numbers.size(); i++){
             answer += to_string(numbers[i]);
         }
         return answer;
     }
 };
```


