#include<vector>
using namespace std;

void bubble_sort(vector<int> array) {
	int i, j;
	for( i = 0; i < array.size() - 1; i++)
		for(j = 0; j < array.size() - 1 - i; j++)
			if(array[j] > array[j + 1])
				swap(array[j], array[j + 1]);
}