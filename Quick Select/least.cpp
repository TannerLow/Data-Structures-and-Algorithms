#include <iostream>

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

int kLeast(int k, int* arr, int size){
    int start = 0, end = size-1, element = k-1;
    while(true){
        int p = partition(start,end,arr);
        if(p > element)
            end = p-1;
        else if(p < element)
            start = p+1;
        else
            return arr[element];
    }
    return 0;
}

int main(){
    int arr[] = {1,10,2,5,18,7,6};
    int size = sizeof arr / sizeof arr[0];
    
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    
    cout << endl;
    cout << kLeast(3,arr,size);
    return 0;
}
