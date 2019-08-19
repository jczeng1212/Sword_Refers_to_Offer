#include<iostream>
#include<vector>
using namespace std;

/*  递归算法超时
运行超时:您的程序未能在规定时间内运行结束，请检查是否循环有错或算法复杂度过大。
case通过率为0.00%
*/
class Solution1 {
public:
    int Fibonacci(int n) {
        if( n == 0 ){
            return 0;
        }
        if( n == 1 ){
            return 1;
        }

        return Fibonacci(n - 1) + Fibonacci(n - 2 );

    }
};

/*
思路：由f(0)和f(1)求得f(2)，再由f(1)和f(2)求得f(3)，...
*/
class Solution {
public:
    int Fibonacci(int n){
        vector<int> temp;
        temp.push_back(0);
        temp.push_back(1);
        for( int i = 2; i <= n; i++ ){
            temp.push_back(temp[i-1] + temp[i-2]);
        }

        return temp[n];

    }

};


class Solution {
public:
    int Fibonacci(int n) {
        if(n <= 0)
            return 0;
        if(n == 1)
            return 1;
        int first = 0, second = 1, third = 0;
        for (int i = 2; i <= n; i++) {
            third = first + second;
            first = second;
            second = third;
        }
        return third;
    }
};


int main(){
    Solution solution;
    
    cout << solution.Fibonacci(3) << endl;


    return 0;
}