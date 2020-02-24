#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    void Insert(int num)
    {
        data.push_back(num);
    }

    double GetMedian()
    { 
        sort(data.begin(), data.end()+1);
        int len = data.size();
        if (len % 2 == 0) {
            return (data[len/2] + data[len/2-1]) / 2;
        } else {
            return data[len/2];
        }
    }

private:
    vector<int> data;

};



//链接：https://www.nowcoder.com/questionTerminal/9be0172896bd43948f8a32fb954e1be1?f=discussion
//来源：牛客网
//用一个大顶堆和一个小顶堆，维持大顶堆的数都小于等于小顶堆的数，且两者的个数相等或差1。平均数就在两个堆顶的数之中。

class Solution {
    priority_queue<int, vector<int>, less<int> > p;     //大顶堆
    priority_queue<int, vector<int>, greater<int> > q;  //小顶堆
     
public:
    void Insert(int num){
        if (p.empty() || num <= p.top()) 
            p.push(num);
        else 
            q.push(num);
        
        if(p.size() == q.size() + 2) 
            q.push(p.top()), p.pop();
        
        if(p.size() + 1 == q.size()) 
            p.push(q.top()), q.pop();
    }
    double GetMedian(){ 
      return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
    }
};

/*
//链接：https://www.nowcoder.com/questionTerminal/9be0172896bd43948f8a32fb954e1be1?toCommentId=2823569
//来源：牛客网
class Solution {
public:
    void Insert(int num)
    {
        if(left.empty() || num <= left.top()){
            left.push(num);
        }else{
            right.push(num);
        }
        // 左边大顶堆的大小最多可以比右边小顶堆大1（奇数次输入）
        if(left.size() == right.size() + 2){
            right.push(left.top());
            left.pop();
        }
        // 因为最后返回的只有可能是左边大顶堆的堆顶，所以右边小顶堆的大小不能比左边小顶堆大
        if(left.size() + 1 == right.size()){
            left.push(right.top());
            right.pop();
        }
    }
    double GetMedian()
    {
        return left.size() == right.size() ? (left.top() + right.top())/2\. : left.top();
    }
private:
    // 右边小顶堆的元素都大于左边大顶堆的元素，并且左边元素的个数，要么与右边相等（偶数次输入），要么比右边大1（奇数次输入）
    priority_queue, less > left; // 大顶堆
    priority_queue, greater > right; // 小顶堆
};
*/