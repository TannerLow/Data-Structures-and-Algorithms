#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void populate(int* arr, int size){
    srand(time(0));
    for(int i = 0; i < size; i++)
        arr[i] = rand() % 201 - 100;
}

void swap(int i, int j, int* arr){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//returns the index where the pivot was placed after partitioning
int absPartition(int start, int end, int* arr){
    int left = start, right = end-1, pivot = end;
    while(true){
        while(abs(arr[left]) <= abs(arr[pivot]) && left < pivot)
            left++;
        while(abs(arr[right]) > abs(arr[pivot]) && right >= 0)
            right--;
        if(left < right)
            swap(left,right,arr);
        else{
            swap(left,pivot,arr);
            return left;  
        }
    }
}

int partition(int start, int end, int* arr){
    int left = start, right = end-1, pivot = end;
    while(true){
        while(arr[left] <= arr[pivot] && left < pivot)
            left++;
        while(arr[right] > arr[pivot] && right >= 0)
            right--;
        if(left < right)
            swap(left,right,arr);
        else{
            swap(left,pivot,arr);
            return left;   
        }
    }
}

//returns the index of the kth least element
int absQuickSelect(int k, int* arr, int size){
    int start = 0, end = size-1, element = k-1;
    while(true){
        int p = absPartition(start,end,arr);
        if(p > element)
            end = p-1;
        else if(p < element)
            start = p+1;
        else
            return element;
    }
    return 0;
}

int quickSelect(int k, int* arr, int size){
    int start = 0, end = size-1, element = k-1;
    while(true){
        int p = partition(start,end,arr);
        if(p > element)
            end = p-1;
        else if(p < element)
            start = p+1;
        else
            return element;
    }
    return 0;
}

int median(int* arr, int size){
    return quickSelect( (size-1)/2 +1, arr, size );
}

//returns k closest numbers to the median in O(n)
int* kClosestNumbers(int k, int* arr, int size){
    int pos = absQuickSelect(k+1,arr,size);
    int* kClosest = new int[k];
    for(int i = 0, j = 0; i <= k; i++)
        if(arr[i] != 0 || i-j > 0)
            kClosest[j++] = arr[i];
    return kClosest;
} 

int main(){
    int n, k;
    cout << "Input a value, n: ";
    cin >> n;
    
    //Create, populate, and print array
    int* arr = new int[n];
    populate(arr,n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
        
    cout << "Input a value 1-n, k: ";
    cin >> k;
    int medianVal = arr[median(arr,n)]; //O(n)
    cout << "Median: " << medianVal << endl;
    
    //Calculate diff O(n) time O(n) memory
    int* diff = new int[n];
    for(int i = 0; i < n; i++)
        diff[i] = arr[i] - medianVal;
    
    //Get k closest numbers O(n)
    int* kClosest = kClosestNumbers(k,diff,n);
    for(int i = 0; i < k; i++)
        cout << kClosest[i] + medianVal << " "; //O(k)
    cout << endl;
    //total O(n + n + n + k), k < n = O(n)
}