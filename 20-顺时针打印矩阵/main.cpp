#include<vector>
using namespace std;

//可能用到递归
//matrix[0].size()为矩阵的边长
//里面的边长为外面的边长的一半
//边长为1的时候停止
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        if ( matrix.empty() ) {
            return result;
        }
        if ( matrix.size() == 1 && matrix[0].size() == 1 ) {
            return matrix[0];
        }

        RMatrix(vector<vector<int> > matrix, vector<int> result, int edgesize);

        return result;
    }

private:
        RMatrix(vector<vector<int> > matrix, vector<int> &result, int edgesize) {
            if (edgesize == 1) {
                return;
            }
            for()       //可以早草稿纸上推算出，当该最外层矩阵的边长edgesize为n，则该最外层矩阵长度为(n-1)*4
        }
};


//链接：https://www.nowcoder.com/questionTerminal/9b4c81a02cd34f76be2659fa0d54342a?f=discussion
//来源：牛客网
/*
    思想，用左上和右下的坐标定位出一次要旋转打印的数据，一次旋转打印结束后，往对角分别前进和后退一个单位。
    提交代码时，主要的问题出在没有控制好后两个for循环，需要加入条件判断，防止出现单行或者单列的情况。
 */
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res;
         
        // 输入的二维数组非法，返回空的数组
        if (row == 0 || col == 0)  return res;
         
        // 定义四个关键变量，表示左上和右下的打印范围
        int left = 0, top = 0, right = col - 1, bottom = row - 1;
        while (left <= right && top <= bottom)
        {
            // left to right
            for (int i = left; i <= right; ++i)  res.push_back(matrix[top][i]);
            // top to bottom
            for (int i = top + 1; i <= bottom; ++i)  res.push_back(matrix[i][right]);
            // right to left
            if (top != bottom)
            for (int i = right - 1; i >= left; --i)  res.push_back(matrix[bottom][i]);
            // bottom to top
            if (left != right)
            for (int i = bottom - 1; i > top; --i)  res.push_back(matrix[i][left]);
            left++,top++,right--,bottom--;
        }
        return res;
    }
};



//链接：https://www.nowcoder.com/questionTerminal/9b4c81a02cd34f76be2659fa0d54342a?f=discussion
//来源：牛客网
/*
解题思路：顺时针打印就是按圈数循环打印，一圈包含两行或者两列，在打印的时候会出现某一圈中只包含一行，
要判断从左向右打印和从右向左打印的时候是否会出现重复打印，同样只包含一列时，要判断从上向下打印和从下向上打印的时候是否会出现重复打印的情况
*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        res.clear();
        int row = matrix.size();    //行数
        int collor = matrix[0].size();  //列数
        
        //计算打印的圈数
        int circle = ((row<collor?row:collor) - 1)/2+1;   //圈数
        for (int i = 0; i < circle; i++) {
            //从左向右打印
            for (int j = i; j < collor - i; j++)
                res.push_back(matrix[i][j]);         
            //从上往下的每一列数据
            for (int k = i + 1; k < row - i; k++)
                res.push_back(matrix[k][collor-1-i]);
            //判断是否会重复打印(从右向左的每行数据)
            for (int m = collor - i - 2; (m >= i) && (row - i - 1 != i); m--)
                res.push_back(matrix[row-i-1][m]);
            //判断是否会重复打印(从下往上的每一列数据)
            for (int n = row - i - 2; (n > i) && (collor - i - 1 != i); n--)
                res.push_back(matrix[n][i]);}
        return res;
    }
};