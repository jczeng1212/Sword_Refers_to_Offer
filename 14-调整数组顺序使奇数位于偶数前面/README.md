# 14-调整数组顺序使奇数位于偶数前面

牛客网链接：[14-调整数组顺序使奇数位于偶数前面](https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

题目描述

> 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。



## 1.一刷情况

**日期**：2020.01.31

**Code**：

```c++
//利用两个队列：将偶数放入一个队列，将奇数放入另外一个队列
//最后，将两个队列中的元素依次按照题目要求放入vector的array中

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        //判空
        //if( array.size() == 0 ){
        //    
        //}
        
        queue<int> q1, q2;
        for( int i=0; i<array.size(); i++){
            if( array[i]%2 == 0 ){
                //偶数放入q1
                q1.push(array[i]);
            }else{
                //奇数放入q2
                q2.push(array[i]);
            }//if
        }//for

        array.clear();
        while( !q2.empty() ){
            array.push_back(q2.front());
            q2.pop();
        }
        while( !q1.empty() ){
            array.push_back(q1.front());
            q1.pop();
        }
        
    }
};

//【解法2】一种类似于插入排序的in-place做法
//【暂时有BUG】
//从头到尾遍历该数组，每遇到一个偶数，就将该偶数拿出来，再将后面的所有数字向前移动一位，再将该偶数放到最后一位上。
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        for( int i=0; i<array.size(); ){
            if( array[i]%2 == 0 ){
                int even = array[i];
                int j = i;
                while( j < array.size()-1 ){
                    array[j] = array[j+1];
                    j++;
                }
                array[j] = even;
                
            }else{
                i++;
            }
        }
        
    }
};
```

**掌握情况**：完全会

**存在问题**：时间复杂度为O(n)，空间复杂度为O(n)





## 参考Code

### Code1 

**日期**：2020.02.01

**方法**：简明扼要说明方法是什么，用了什么数据结构等等。

**时间复杂度**：

**具体思路**：

**Code**：

```c++
//链接：https://www.nowcoder.com/questionTerminal/beb5aa231adc45b2a5dcc5b62c93f593?f=discussion
//来源：牛客网

//两个思路吧，第一个思路：类似冒泡算法，前偶后奇数就交换
class Solution {
public:
    void reOrderArray(vector<int> &array) {
 
        for( int i = 0; i < array.size()-1; i++){
            for( int j = array.size() - 1; j>i; j--){
                if( array[j] % 2 == 1 && array[j - 1]%2 == 0){ //前偶后奇交换
                    swap(array[j], array[j-1]);
                }
            }
        }

        /*作者：牛客1165692号
        链接：https://www.nowcoder.com/questionTerminal/beb5aa231adc45b2a5dcc5b62c93f593?f=discussion
        来源：牛客网

        这个就是冒泡排序的思路，可以自己再纸上画一画。首先确定外层循环次数，即array.size(),然后进行内层循环，代码中是从后面往前面排序，比如2，1，4，3。如果满足前偶后奇数，交换循序，变成1,2,3,4，其中首尾已经排好序了，故结束条件设置为array.size()-i,然后从倒数第二位到顺数第二位再排序。
        其实第一层循环只需要array.size()/2.因为内层循环一次，能将首尾分别拍好一个数字。还有就是可以直接从前面往后面排序。参考楼主的思路：
        */

        for(int i = 0; i < (array.size())/2; i++){
            for(int j = 0; j < (array.size()-i); j++){
                if(((array[j]%2) == 0) && ((array[j+1]%2) == 1)){
                    swap(array[j] ,array[j+1]);
                }
            }
        }
    }
};
 
//第二个思路：再创建一个数组，将偶数保存到一个新数组中
class Solution{
public:
    void reOrderArray(vector<int> &array) {
 
        vector<int> array_temp;
        vector<int>::iterator ib1, ie1;
        ib1 = array.begin();
 
        while( ib1 != array.end() ){    //遇见偶数，就保存到新数组，同时从原数组中删除
            if(*ib1 % 2 == 0) {
                array_temp.push_back(*ib1);
                ib1 = array.erase(ib1);
            }else{
                ib1++;
            }
        }

        vector<int>::iterator ib2, ie2;
        ib2 = array_temp.begin();
        ie2 = array_temp.end();
        
        while( ib2 != ie2 ){
            array.push_back(*ib2);  //将新数组的数添加到老数组
            ib2++;
        }
    }
};
```


