#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void swap(int i, int j, int* arr){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
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
            break;   
        }
    }
    return left;
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

int* maxNumbers(int k,int* arr,int size){
    k = size - k;
    int pos = quickSelect(k,arr,size);
    return arr + pos + 1;
}

int main(){
    //User Input
    int n, k;
    cout << "Size of array, n?" << endl;
    cin >> n;
    cout << "Enter a number 1-n" << endl;
    cin >> k;
    cout << endl;
    
    //Generate Array
    int* arr = new int[n];
    srand(time(0));
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 201 - 100;
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    
    //Part A kth least element
    cout << "Kth least element: " << arr[quickSelect(k,arr,n)] << endl;
    
    //Part B k max maxNumbers
    int* newArray = maxNumbers(k,arr,n);
    cout << "K max numbers: ";
    for(int i = 0; i < k; i++)
        cout << newArray[i] << " ";
    cout << endl;
    
    return 0;
}
