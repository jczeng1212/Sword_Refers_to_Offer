//插入排序算法思想：每趟将一个元素，按照其关键字的大小插入到它前面已经排序的子序列中(在已排序子序列中，从后向前扫描，找到相应位置并插入)，依此重复，直到插入全部元素。
//时间复杂度：O(n^2)

void InsertionSort(int arr[], int len){
    for(int i=1; i<len; i++){
        int key = arr[i];   //key为每次选中进行比较的数，初始从序列中的第二个开始
        int j = i-1;
        
        while( (j>=0) && (key<arr[j]) ){
            arr[j+1] = arr[j];    //元素后移
            j--;
        }

        arr[j+1] = key;

    }
}