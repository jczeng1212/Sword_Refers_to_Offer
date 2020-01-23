//一行一行的找，行吗？
//每一行中，遇到target比数组中元素大的即该行查找失败，换到下一行，若查找成功，返回true
//最后一行结束后，即全部查找失败，返回false


class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //需要进行安全性检查吗？

        int i = 0;
        int j = 0;

        for( i=0; i<array.size(); ){
            for( j=0; j<array[i].size(); ){
                if( target == array[i][j] ){
                    return true;
                }else if(target < array[i][j]){
                    j++;
                }else if(target > array[i][j]){
                    i++;
                    break;
                }
            }


            if( i==array.size() && target>array[i][j] ){
                return false;
            }
        }
    }
};

//code1
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        for( int i=0; i<array.size(); i++){
            //每行进行二分查找
            int low = 0;
            int high = array[i].size() - 1;
            
            while( low <= high ){
                int mid = (low + high) / 2;
                if( target > array[i][mid] )
                    low = mid + 1;
                else if( target < array[i][mid] )
                    high = mid - 1;
                else
                    return true;
            }

        }
        return false;
 
    }
};


//code2
//从左下角开始查找:
//当要查找数字比左下角数字大时,右移
//要查找数字比左下角数字小时，上移  
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rowCount = array.size();
        int colCount = array[0].size();
        int i, j;
        for( i=rowCount-1, j=0; i>=0 && j<colCount; ){
            if( target == array[i][j] )
                return true;
            
            if( target < array[i][j] ){
                i--;
                continue;
            }

            if( target > array[i][j] ){
                j++;
                continue;
            }
        }

        return false;
    }
};

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        // array是二维数组，这里没做判空操作
        int rows = array.size();
        int cols = array[0].size();
        int i = rows - 1, j = 0;//左下角元素坐标
        
        while( i >= 0 && j<cols ){//使其不超出数组范围
            if( target < array[i][j] )
                i--;  //查找的元素较小，往上找
            else if( target > array[i][j] )
                j++;  //查找元素较大，往右找
            else
                return true;//找到
        }
        return false;
    }
};