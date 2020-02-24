#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

//【未通过，超时】
//时间复杂度：O(n*window_size)
//我的解法
//模拟滑动窗口的过程，手写寻找窗口中最大值函数
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> result;
        if (size == 0 || num.empty()) {
            return result;
        }

        for (int left = 0, right = size - 1; right <= num.size() - 1; left++, right++) {
            int temp = findMax(num, left, right);
            result.push_back(temp);
        }

        return result;

    }

    int findMax(vector<int> num, int left, int right) {
        int max = num[left];
        while (left < right) {
            left++;
            if (max < num[left]) {
                max = num[left];
            }
        }
    }
};


//链接：https://www.nowcoder.com/questionTerminal/1624bc35a45c42c0bc17d17fa0cba788?f=discussion
//来源：牛客网
//时间复杂度：O(n)
//双端队列deque s保存有可能是滑动窗口最大值的数字的下标
//s的队尾：插入————新加入的下标插入队尾(pop_back); 删除————队列中已有的数字小于待存入的数字，这些数字已不可能是滑动窗口的最大值，从队尾删除
//s的队头：仅删除————队列头部的数字从窗口里滑出，则从队头删除(pop_front). 保证队首为当前窗口最大值下标
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> s;   //双端队列
        for (unsigned int i = 0; i < num.size(); ++i) {
            while(s.size() && num[s.back()] <= num[i])  //从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
                s.pop_back();
            while(s.size() && i - s.front() + 1 > size)   //当窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
                s.pop_front();
            s.push_back(i);     //把每次滑动的num下标加入队列
            if (size && i + 1 >= size)   //当滑动窗口首地址i大于等于size时才开始写入窗口最大值
                res.push_back( num[s.front()] );
        }
        return res;
    }
};