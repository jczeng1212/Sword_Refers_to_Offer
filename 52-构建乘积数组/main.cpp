#include<vector>
using namespace std;

//剑指Offer解法
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B;
        if( A.empty() ){
            return B;
        }

        const int len = A.size();

        //计算下三角
        B.push_back(1);
        for( int i = 1; i < len; i++){
            B.push_back(B[i-1] * A[i-1]);
        }

        //计算上三角，同时把B给计算出来
        int temp = 1;
        for( int j = len - 2; j >= 0; j--){
            temp *= A[j+1];
            B[j] *= temp;
        }

        return B;
    }
};
