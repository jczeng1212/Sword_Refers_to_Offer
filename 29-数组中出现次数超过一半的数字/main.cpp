#include<iostream>
#include<vector>
using namespace std;

//首先，没有给出该数组长度
//一种方法是：设置一个辅助数组记录数组中所有元素出现的个数，在这个过程中同时记录数组的长度是多少。
//然后在辅助数组中寻找个数大于数组长度一半的数
//时间复杂度：O(n),空间复杂度:O(n)

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        vector<int> countArray;


    
    }
};


//先将中位数找出来
//再统计数组中该中位数出现的次数，对其出现次数是否大于数组个数一半进行确认
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