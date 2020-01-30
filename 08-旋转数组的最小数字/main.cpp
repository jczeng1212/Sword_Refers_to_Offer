class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if ( rotateArray.size() == 0 )
            return 0;

        int i = 0;
        while( rotateArray[i] <= rotateArray[i+1] ){
            i++;
        }

        return rotateArray[i+1];
    }
};

//链接：https://www.nowcoder.com/questionTerminal/9f3231a991af4f55b95579b44b7a01ba?f=discussion
//来源：牛客网

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int size = rotateArray.size();
        if(size == 0){
            return 0;
        }//if

        int left = 0, right = size - 1;
        int mid = 0;
        // rotateArray[left] >= rotateArray[right] 确保旋转
        while( rotateArray[left] >= rotateArray[right] ){
            // 分界点
            if(right - left == 1){
                mid = right;
                break;
            }//if

            mid = left + (right - left) / 2;
            
            // rotateArray[left] rotateArray[right] rotateArray[mid]三者相等
            // 无法确定中间元素是属于前面还是后面的递增子数组
            // 只能顺序查找
            if(rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid]){
                return MinOrder(rotateArray,left,right);
            }//if

            // 中间元素位于前面的递增子数组
            // 此时最小元素位于中间元素的后面
            if(rotateArray[mid] >= rotateArray[left]){
                left = mid;
            }//if
            // 中间元素位于后面的递增子数组
            // 此时最小元素位于中间元素的前面
            else{
                right = mid;
            }//else
        }//while

        return rotateArray[mid];
    }
private:
    // 顺序寻找最小值
    int MinOrder(vector<int> &num, int left, int right){
        int result = num[left];
        for(int i = left + 1;i < right;++i){
            if(num[i] < result){
                result = num[i];
            }//if
        }//for
        return result;
    }
};