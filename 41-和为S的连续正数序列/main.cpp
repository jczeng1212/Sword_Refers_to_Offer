#include<vector>
#include<algorithm>
using namespace std;

//建立一个数字之上的滑动窗口，滑动窗口的两边使用双指针标识
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > result;
        if (sum <= 0) {
            return result;
        }

        int plow = 1;
        int phigh = 2;

        while (phigh > plow) {
            //由于是连续的、差为1的一个序列，那么求和公式是(a1+an)*n/2
            int cur = (phigh + plow) * (phigh - plow + 1) / 2;

            if (cur == sum) {   //相等，那么就将窗口范围的所有数添加进结果集
                vector<int> temp;
                for (int i = plow; i <= phigh; i++) {
                    temp.push_back(i);
                }
                result.push_back(temp);
                plow++; //这个plow++必不可少
            } else if (cur < sum) { //如果当前窗口内的值之和小于sum，那么右边窗口右移一下
                phigh++;
            } else {    //如果当前窗口内的值之和大于sum，那么左边窗口右移一下
                plow++;
            }
        }//while

        return result;
    }
};


//【并没有通过】
//链接：https://www.nowcoder.com/questionTerminal/c451a3fd84b64cb19485dad758a55ebe?f=discussion
//来源：牛客网
/*
1）由于我们要找的是和为S的连续正数序列，因此这个序列是个公差为1的等差数列，而这个序列的中间值代表了平均值的大小。
假设序列长度为n，那么这个序列的中间值可以通过（sum/n）得到，知道序列的中间值和长度，也就不难求出这段序列了。
2）满足条件的n分两种情况：
n为奇数时，序列中间的数正好是序列的平均值，所以条件为：(n & 1) == 1 && sum % n == 0；
n为偶数时，序列中间两个数的平均值是序列的平均值，而这个平均值的小数部分为0.5，所以条件为：(sum % n) * 2 == n.
3）由题可知n >= 2，那么n的最大值是多少呢？我们完全可以将n从2到S全部遍历一次，但是大部分遍历是不必要的。为了让n尽可能大，我们让序列从1开始，
根据等差数列的求和公式：sum = (1 + n) * n / 2，得到:n<sqrt(2sum)

最后举一个例子，假设输入sum = 100，我们只需遍历n = 13~2的情况（按题意应从大到小遍历），n=8时，得到序列[9, 10, 11, 12, 13, 14, 15, 16]； n=5时，得到序列[18, 19, 20, 21, 22]。
完整代码：时间复杂度为O(sqrt(n))

【为什么是(sum % n) * 2 == n】
{1,2,3,4},sum/n = 2.5,{2.5,2.5,2.5,2.5}而计算机取余的时候可以看成是{2,2,2,2}，最后余2，可以看到每个数都与相除的时候差0.5，n*0.5=sum%n。
作者：wildrage
链接：https://www.nowcoder.com/questionTerminal/c451a3fd84b64cb19485dad758a55ebe?f=discussion
来源：牛客网
余数0.5是sum/n后得到的数带0.5，比如50/4等于12.5。而这0.5*n后的得到的数等于sum%n所得到的数，例如50%4等于2。也就得出0.5*n=sum%n。转一下就是(sum % n) * 2 == n 。至于为什么是0.5见楼主解释。
*/
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > result;
        if (sum <= 0) {
            return result;
        }

        for (int n = (int)sqrt(2*sum); n >= 2; n++) {
            if ((n & 1) == 1 && (sum % n == 0) || (sum % n) * 2 == n) {
            //if (( i&1 && !(sum%i)) || (sum%i)*2 == i)
                vector<int> temp;
                for (int j = 0, k = (sum / n) - (n - 1) / 2; j < n; j++, k++) { //k为这段序列的值，初始值为(sum / n) - (n - 1) / 2
                    temp.push_back(k);
                }
                result.push_back(temp);
            }//if
        }//for

        return result;
    }
};