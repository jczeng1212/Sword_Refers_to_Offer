# 29-数组中出现次数超过一半的数字

牛客网链接：[29-数组中出现次数超过一半的数字](https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

题目描述

> 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。



## 1.一刷情况

**日期**：2020.01.

**Code**：

```c++

```

**掌握情况**：完全不会/会一半/完全会

**存在问题**：





## 参考Code

### Code1 

**日期**：2020.01.31

**方法**：利用**出现次数超过一半**这个条件——利用中位数进行判断

**时间复杂度**：**O(NlogN)**

**具体思路**：链接：https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163?f=discussion
来源：牛客网

思路一：**数组排序后，如果符合条件的数存在，则一定是数组中间那个数**。（比如：1，2，2，2，3；或2，2，2，3，4；或2，3，4，4，4等等） 

这种方法虽然容易理解，但由于涉及到快排sort，其时间复杂度为**O(NlogN)**并非最优； 

**Code**：

```c++
//1.将数组进行排序
//2.将中位数找出来
//3.再统计数组中该中位数出现的次数，对其出现次数是否大于数组个数一半进行确认
//sort由快排实现，其时间复杂度为O(NlogN)并非最优

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        // 因为用到了sort，时间复杂度O(NlogN)，并非最优
        if( numbers.empty() ) 
            return 0;
        
        sort( numbers.begin(), numbers.end()); // 排序，取数组中间那个数——即中位数
        int middle = numbers[ numbers.size()/2 ];
         
        int count=0; // 统计middle数出现次数
        for( int i=0; i<numbers.size(); ++i){
            if( numbers[i]==middle ) 
                ++count;
        }
         
        return (count>numbers.size()/2) ? middle :  0;
    }
};
```



### Code2 

**日期**：2020.01.31

**方法**：简明扼要说明方法是什么，用了什么数据结构等等。

**时间复杂度**：**O(NlogN)**

**具体思路**：链接：https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163?f=discussion
来源：牛客网

思路二：**如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。** 

在遍历数组时保存两个值：一是数组中的一个数字，二是其出现的次数。遍历下一个数字时，若它与之前保存的数字相同，则次数加1，否则次数减1；若次数为0，则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。

**Code**：

```c++
//维护两个变量：
//result 和 times
//和上面相同的地方是，先找出这个可能的数字，然后再进行确认
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers){
        if( numbers.empty() )
            return 0;
         
        // 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
        int result = numbers[0];
        int times = 1; // 次数
        
        for( int i=1; i<numbers.size(); ++i){
            if( times == 0 ){
                // 更新result的值为当前元素，并置次数为1
                result = numbers[i];
                times = 1;
            }else if( numbers[i] == result ){
                ++times; // 相同则加1
            }else{
                --times; // 不同则减1               
            }
        }
         
        // 判断result是否符合条件，即出现次数大于数组长度的一半
        //例如：对于12345666这种情况，第一个for循环结束最后得到的result=6，但是长度却为3，不到数组长度的1/2，所以要再算次数
        times = 0;
        for(int i=0; i<numbers.size(); ++i){
            if( numbers[i] == result )
                ++times;
        }
         
        return (times > numbers.size()/2) ? result : 0;
    }
};
```