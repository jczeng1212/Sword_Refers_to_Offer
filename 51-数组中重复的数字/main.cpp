class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        for( int i = 0; i < length; i++){
            int index = numbers[i];

            if( index >= length ){
                index -= length;
            }

            if( numbers[index] >= length ){
                *duplication = index;
                return true;
            }

            numbers[index] = numbers[index] + length;
        }

        return false; 
    }
};



//链接：https://www.nowcoder.com/questionTerminal/623a5ac0ea5b4e5f95552655361ae0a8?f=discussion
//来源：牛客网

//不需要额外的数组或者hash table来保存，题目里写了数组里数字的范围保证在0 ~ n-1 之间
//所以可以利用现有数组设置标志，当一个数字被访问过后，可以设置对应位上的数 + n，之后再遇到相同的数时
//会发现对应位上的数已经大于等于n了，那么直接返回这个数即可。

int find_dup( int numbers[], int length) {

    for( int i = 0; i < length; i++){
        int index = numbers[i];

        if( index >= length ){
            index -= length;
        }

        if( numbers[index] >= length ){
            return index;
        }

        numbers[index] = numbers[index] + length;

    }   

    return - 1 ; 

}



//链接：https://www.nowcoder.com/questionTerminal/623a5ac0ea5b4e5f95552655361ae0a8?f=discussion
//来源：牛客网

bool duplicate(int numbers[], int length, int* duplication) {
    for( int i = 0; i != length; ++i){
        int index = numbers[i] % length;
        if( numbers[index] >= length){
            *duplication = index;
            return 1;
        }              
        numbers[index] += length;  
    }
    return 0;
}


//链接：https://www.nowcoder.com/questionTerminal/623a5ac0ea5b4e5f95552655361ae0a8?f=discussion
//来源：牛客网
//也即剑指offer上的解法
/*
1、判断输入数组有无元素非法
2、从头扫到尾，只要当前元素值与下标不同，就做一次判断,numbers[i]与numbers[numbers[i]]，相等就认为找到了
重复元素，返回true,否则就交换两者，继续循环。直到最后还没找到认为没找到重复元素，返回false
*/
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if( length <= 0 || numbers == NULL )
            return false;
        
        //判断每一个元素是否非法
        for(int i=0;i<length;++i){
            if( numbers[i] <= 0 || numbers[i] > length-1 )
                return false;
        }

        for( int i = 0; i < length; ++i){
            while( numbers[i] != i ){
                if( numbers[i] == numbers[numbers[i]] ){
                    *duplication = numbers[i];
                    return true;
                }
                //交换numbers[i]和numbers[numbers[i]]
                int temp = numbers[i];
                numbers[i] = numbers[temp];
                numbers[temp] = temp;
            }
        }
        return false;
         
    }
};