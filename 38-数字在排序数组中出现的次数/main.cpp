
//按顺序查找
//时间复杂度：O(n)
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int num = 0;
        for( int i = 0; i < data.size(); i++){
            if( data[i] == k ){
                num++;
            }
        }//for

        return num;
    }
};

//如何降低时间复杂度呢？
//利用已排序的性质-->二分查找



//链接：https://www.nowcoder.com/questionTerminal/70610bf967994b22bb1c26f9ae901fa2?f=discussion
//来源：牛客网
//因为data中都是整数，所以可以稍微变一下，不是搜索k的两个位置，而是搜索k-0.5和k+0.5
//这两个数应该插入的位置，然后相减即可。
//时间复杂度：O(logn)
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return biSearch(data, k+0.5) - biSearch(data, k-0.5) ;
    }
private:
    int biSearch(const vector<int> & data, double num){
        int s = 0, e = data.size()-1;     
        while( s <= e ){
            int mid = (e - s)/2 + s;
            if( data[mid] < num )
                s = mid + 1;
            else if( data[mid] > num )
                e = mid - 1;
        }
        return s;   //return e; 也可以
    }
};


//链接：https://www.nowcoder.com/questionTerminal/70610bf967994b22bb1c26f9ae901fa2?f=discussion
//来源：牛客网
//利用C++ stl的二分查找
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        auto resultPair = equal_range(data.begin(), data.end(),k);
        return resultPair.second - resultPair.first;
    }
};


//链接：https://www.nowcoder.com/questionTerminal/70610bf967994b22bb1c26f9ae901fa2?f=discussion
//来源：牛客网
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
      //单纯的利用了count函数。。。。。
        return count(data.begin(),data.end(),k);
    }
};
