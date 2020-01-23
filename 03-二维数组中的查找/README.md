# 03-二维数组中的查找

牛客网链接：[03-二维数组中的查找](https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

题目描述

> 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。



## 1.一刷情况

**日期**：2020.01.23

**Code**：

```c++
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //需要进行安全性检查吗？

        int i = 0;
        int j = 0;

        for( i=0; i<array.size(); ){
            for( j=0; j<array[i].size(); ){
                if( target == array[i][j] ){
                    return true;
                }else if(target < array[i][j]){
                    j++;
                }else if(target > array[i][j]){
                    i++;
                    break;
                }
            }


            if( i==array.size() && target>array[i][j] ){
                return false;
            }
        }
    }
};
```

**掌握情况**：完全不会/会一半/完全会

**存在问题**：方法是暴力检索，但是出了问题。

```
段错误:您的程序发生段错误，可能是数组越界，堆栈溢出（比如，递归调用层数太多）等情况引起点击对比用例标准输出与你的输出
case通过率为0.00%
```







## 参考Code

### 两种思路

```
一种是：把每一行看成有序递增的数组，利用二分查找，通过遍历每一行得到答案，时间复杂度是nlogn。见code1。

另外一种思路是：利用二维数组由上到下，由左到右递增的规律，那么选取右上角或者左下角的元素a[row] [col]与target进行比较，
当target小于元素a[row] [col]时，那么target必定在元素a所在行的左边, 即col-- ;
当target大于元素a[row] [col]时，那么target必定在元素a所在列的下边,即row++ ;
见code2.


整理自：牛客网，链接：https://www.nowcoder.com/questionTerminal/abc3fe2ce8e146608e868a70efebf62e?f=discussion
```





### Code1 

**日期**：2020.01.23

**方法**：按照刷题基础的说明，简明扼要说明方法是什么，用了什么数据结构等等。

**具体思路**：

**Code**：

```c++
链接：https://www.nowcoder.com/questionTerminal/abc3fe2ce8e146608e868a70efebf62e?f=discussion
来源：牛客网

class Solution {
    public bool Find(int target, vector<vector<int> > array) {
        for( int i=0; i<array.size(); i++){
            int low=0;
            int high=array[i].length-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(target>array[i][mid])
                    low=mid+1;
                else if(target<array[i][mid])
                    high=mid-1;
                else
                    return true;
            }
        }
        return false;
 
    }
}
```





### Code2

**日期**：2020.01.23

**方法**：按照刷题基础的说明，简明扼要说明方法是什么，用了什么数据结构等等。

**具体思路**：

**Code**：

```c++
//链接：https://www.nowcoder.com/questionTerminal/abc3fe2ce8e146608e868a70efebf62e?f=discussion
//来源：牛客网

//从左下角开始查找，
//当要查找数字比左下角数字大时,右移
//要查找数字比左下角数字小时，上移  

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rowCount = array.size();
        int colCount = array[0].size();
        int i, j;
        for( i=rowCount-1, j=0; i>=0 && j<colCount; ){
            if( target == array[i][j] )
                return true;
            
            if( target < array[i][j] ){
                i--;
                continue;
            }

            if( target > array[i][j] ){
                j++;
                continue;
            }
        }

        return false;
    }
};


//链接：https://www.nowcoder.com/questionTerminal/abc3fe2ce8e146608e868a70efebf62e?f=discussion
//来源：牛客网
//思想同上
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        // array是二维数组，这里没做判空操作
        int rows = array.size();
        int cols = array[0].size();
        int i = rows - 1, j = 0;//左下角元素坐标
        
        while( i >= 0 && j<cols ){//使其不超出数组范围
            if( target < array[i][j] )
                i--;  //查找的元素较小，往上找
            else if( target > array[i][j] )
                j++;  //查找元素较大，往右找
            else
                return true;//找到
        }
        return false;
    }
};
```


