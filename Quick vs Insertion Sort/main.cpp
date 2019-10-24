#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <utility>

using namespace std;

void populate(int* arr, int size){
    srand(time(0));
    for(int i = 0; i < size; i++)
        arr[i] = rand() % 10000 - 5000;
}

void swap(int i, int j, int* arr){
    int temp = arr[i];
    arr[i]   = arr[j];
    arr[j]   = temp;
} 

void insertionSort(int* arr, int size){
    for(int i = 0,j; i < size; i++)
        for(int j = i; j > 0 && arr[j] < arr[j-1]; j--)
            swap(j, j-1,arr);
}

int medianOf3(int* arr, int start, int end){
    pair<int,int> x(arr[start], start),
                  y(arr[(start+end)/2], (start+end)/2),
                  z(arr[end], end);
    return max({x,y,z}).second;
}

int partition(int* arr, int start, int end){
    int left = start, right = end-1, pivot = end;
    swap( medianOf3(arr,start,end), right+1, arr );
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

void quickSort(int* arr, int left, int right){
    if(left < right){
        int pos = partition(arr,left,right);
        quickSort(arr, left , pos-1);
        quickSort(arr, pos+1, right);
    }
}

int main(){
    int n = 1000;
    int* a = new int[n];
    populate(a,n);
    insertionSort(a,n);
    quickSort(a,0,n-1);
}