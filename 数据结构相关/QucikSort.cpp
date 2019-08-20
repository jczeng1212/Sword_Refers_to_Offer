#include<iostream>
using namespace std;

int partition(int A[], int low, int high);

void QuickSort(int A[], int low, int high){
    if( low < high ){
        int pivotpos = partition(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
    
}

int partition(int A[], int low, int high){
    int pivot = A[low]; //A的第一个元素作为枢轴值

    while( low < high ){
        while( low < high && A[high] >= pivot ){
            high--;
        }
        A[low] = A[high];   //A[low]在上面已经提前保存

        while( low < high && A[low] <= pivot ){
            low++;
        }
        A[high] = A[low];
    }
    //cout << "pivot = " << pivot << endl;
    //cout << "A[low] =" << A[low] << endl;
    A[low] = pivot; //枢轴元素放到最终位置
    
    return low;

}

int main(){
    int A[] = {4, 5, 1, 2, 3};

    QuickSort(A, 0, 4);

    for( int i = 0; i <= 4; i++){
        cout << A[i] << " ";
    }

    return 0;
}