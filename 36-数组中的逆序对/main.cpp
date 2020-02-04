#include<vecotor>
using namespace std;
//链接：https://www.nowcoder.com/questionTerminal/96bd6684e04a44eb80e6a68efc0ec6c5?f=discussion
//来源：牛客网

class Solution {
public:
    int InversePairs(vector<int> data){
        int length = data.size();
        if( length <= 0 )
            return 0;
        //vector<int> copy=new vector<int>[length];
        vector<int> copy;
        for( int i = 0; i < length; i++)
            copy.push_back( data[i] );      //把数组数据复制到辅助空间
        long long count = InversePairsCore( data, copy, 0, length-1);
        //delete[]copy;
        return count%1000000007;
    }

    long long InversePairsCore( vector<int> &data, vector<int> &copy, int start, int end){
        if( start == end ){
            copy[start] = data[start];
            return 0;
        }
        int length = (end-start) / 2;   //划分
        long long left = InversePairsCore( copy, data, start, start+length);    //递归求解左半部分
        long long right = InversePairsCore( copy, data, start + length + 1, end);   //递归求解右半部分
        
        int i = start + length;
        int j = end;
        int indexcopy = end;
        long long count = 0;

        while( i >= start && j >= start + length + 1){
            if( data[i] > data[j] ){
                copy[indexcopy--] = data[i--];
                count = count + j - start - length;          //count=count+j-(start+length+1)+1;
            }else{
                copy[indexcopy--] = data[j--];
            }          
        }

        for(; i >= start; i--)
            copy[indexcopy--] = data[i];
        for(; j >= start + length + 1; j--)
            copy[indexcopy--] = data[j];       
        return left+right+count;
    }
};




//链接：https://www.nowcoder.com/questionTerminal/96bd6684e04a44eb80e6a68efc0ec6c5?f=discussion
//来源：牛客网

//这道题debug了好久才提交，总是出现各种问题，得到了很多教训，如注释中的1,2,3
//另外debug时，不仅要观察最后的结果，还要看数组是否真的排序了
class Solution {
public:
    int InversePairs(vector<int> data) {
        //用long long类型否则会超限
        long long num = 0;
        mergesort(data, num, data.begin(), data.end() - 1);
        return num%1000000007;
    }
    //归并排序
    void mergesort(vector<int> &data, long long &num, vector<int>::iterator start, vector<int>::iterator end) {
        if (start == end) return;
        vector<int>::iterator mid = start + (end - start) / 2;
        mergesort(data, num, start, mid);
        mergesort(data, num, mid + 1, end);
        merge(data, num, start, end);
    }
    //合并
    void merge(vector<int> &data, long long &num, vector<int>::iterator start, vector<int>::iterator end) {
        if (start == end) return;
        vector<int>::iterator mid = start + (end - start) / 2;
        //把要合并的两个子数组保存出来
        vector<int> data1(start, mid+1);
        vector<int> data2(mid + 1, end+1);
        
        //两个迭代器分别指向两个数组的末尾
        vector<int>::iterator p = data1.end() - 1;
        vector<int>::iterator q = data2.end() - 1;
        vector<int>::iterator m = end;
        int sz1 = data1.size();
        int sz2 = data2.size();
        
        //合并，当前面数组的元素大于后面时计数加一
        while ( sz1 > 0 && sz2 > 0 ) {
            if (*q<*p) {
                num = q - data2.begin() + 1 + num;  //1、迭代器相减注意顺序
                *m = *p;
                --sz1;
                --m;
                if(sz1>0) --p;  //2、有效迭代器的范围是[begin(),end())，begin()位置已经不可以再自减了
            }
            else {
                *m = *q;
                --sz2;
                --m;
                if(sz2>0)  --q;
            }
        }
        //3、把剩余的放入数组中，一开始分析出来其中一个数组最多只剩一个元素，而没有让迭代器自减
        while (sz1--) {
            *m = *p;
            if (sz1 > 0) {
                --m;
                --p;
            }          
        }      
        while (sz2--) {
            *m = *q;
            if (sz2 > 0) {
                --m;
                --q;
            }  
        }          
    }
};