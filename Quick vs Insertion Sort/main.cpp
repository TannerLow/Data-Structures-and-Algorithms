#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <utility>
#include <chrono>

using namespace std;
using namespace chrono;
typedef chrono::high_resolution_clock timer;

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
    pair<int,int> three[] = {x,y,z};
    sort(three,three+3);
    return three[1].second;
}

int partition(int* arr, int start, int end){
    int left = start, right = end-1, pivot = end;
    swap( medianOf3(arr,start,end), pivot, arr );
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

    auto start = timer::now(), end = start;
    auto duration = duration_cast<microseconds>(start-start);
//Insertion Sort O(n^2)
    for(int i = 0; i < 100; i++){
        populate(a,n);
        start = timer::now();
        insertionSort(a,n);
        end = timer::now();
        duration += duration_cast<microseconds>(end-start);
    }
    auto avgInsertionSort = duration.count()/100;
    cout << "Insertion: " << avgInsertionSort << "us" << endl;
//Quick Sort O(nlogn)
    duration = duration_cast<microseconds>(start-start);
    for(int i = 0; i < 100; i++){
        populate(a,n);
        start = timer::now();
        quickSort(a,0,n-1);
        end = timer::now();
        duration += duration_cast<microseconds>(end-start);
    }
    cout << "QuickSort: " << duration.count()/100 << "us" << endl;
//Time per line of Insertion sort
    cout << (double)avgInsertionSort/(3*n*n)*1000 << "ns" << endl;
}
