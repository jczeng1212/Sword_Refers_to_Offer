#include<vector>
using namespace std;

//暴力法
//超时了
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        int i = 0;
        int count = 0;
        while (count != index) {
            i++;
            if (isUglyNumber(i)) {
                count++;
            }
        }
        return i;
    }

private:
    bool isUglyNumber(int num){
        while (num) {
            if (num % 2 == 0) {
                num /= 2;
            } else if (num % 3 == 0) {
                num /= 3;
            } else if (num % 5 == 0) {
                num /= 5;
            } else if (num == 1) {
                return true;
            } else {
                return false;
            }
        }

    }

};


//链接：https://www.nowcoder.com/questionTerminal/6aa9e04fc3794f68acf8778237ba065b?f=discussion
//来源：牛客网

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index < 7)
            return index;
        vector<int> res(index);
        res[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0, i;
        for (i = 1; i < index; ++i)
        {
            res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
            if (res[i] == res[t2] * 2) t2++;
            if (res[i] == res[t3] * 3) t3++;
            if (res[i] == res[t5] * 5) t5++;
        }
        return res[index - 1];
    }
};