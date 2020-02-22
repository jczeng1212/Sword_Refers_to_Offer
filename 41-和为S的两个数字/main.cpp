#include<vector>
using namespace std;

//这两个数，其中一个大于sum/2，另一个小于sum/2
//array递增，
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        
    }
};


/*
链接：https://www.nowcoder.com/questionTerminal/390da4f7a00f44bea7c2f3d19491311b?f=discussion
来源：牛客网

不要被题目误导了！证明如下，清晰明了：
//输出两个数的乘积最小的。这句话的理解？
假设：若b>a,且存在，
a + b = s;
(a - n ) + (b + m) = s
则：(a - n )(b + m)=ab - bn + am - n*m < ab；说明外层的乘积更小
也就是说依然是左右夹逼法！！！只需要2个指针
1.left开头，right指向结尾
2.如果和小于sum，说明太小了，left右移寻找更大的数
3.如果和大于sum，说明太大了，right左移寻找更小的数
4.和相等，把left和right的数返回
*/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if ( array.size()==0 || array.size()==1 ){
            return result;
        }

        int left = 0;
        int right = array.size() - 1;
        while (left <= right) {
            if (array[left] + array[right] == sum) {
                result.push_back(array[left]);
                result.push_back(array[right]);
                break;
            } else if (array[left] + array[right] < sum) {
                left++;
            } else if (array[left] + array[right] > sum) {
                right--;
            }
        }
        return result;
    }
};