#include <iostream>
#include <array>
#include <stdlib.h>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;
typedef chrono::high_resolution_clock timer;

void swap(int* arr, int a, int b){
    int tmp = arr[a];
    arr[a]  = arr[b];
    arr[b]  = tmp;
}

void populate(int* arr, int size){
    srand(time(0));
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 201 - 100;
    }
}

void selectionSort(int* arr, int size){
    for(int i = 0; i < size; i++){
        int min = size-1;
        for(int j = i; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr,i,min);
    }
}

void maxHeapify(int index, int* arr, int size){
    int left = 2*index + 1, right = 2*index + 2;
    if(right < size){
        int less = (arr[left] > arr[right]) ? left : right;
        if(arr[index] < arr[less]){
            swap(arr, index, less);
            maxHeapify(less, arr, size);
        }
    }
    else if(left < size){
        if(arr[left] > arr[index]){
            swap(arr, left, index);
        }
    }
}

void buildMaxHeap(int* arr, int size){
    for(int i = size-1; i >= 0; i--){
        maxHeapify(i, arr, size);
    }
}

void heapSort(int* arr, int size){
    buildMaxHeap(arr,size);
    for(int i = size-1; i >= 0; i--){
        swap(arr, i, 0);
        maxHeapify(0,arr,i);
    }
}

int main(){
    //User input
    int n;
    cin >> n;

    //Build array
    int* arr = new int[n];
    populate(arr,n);

    //Build max heap
    buildMaxHeap(arr,n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    //heapSort
    heapSort(arr,n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    //compare selection vs heap sort
    auto start = timer::now(), end = timer::now();
    auto duration = duration_cast<microseconds>(start-start);

    delete arr;
    n = 1000;
    arr = new int[1000];

    //Time average Selection sort
    for(int i = 0; i < 100; i++){
        populate(arr,n);
        start = timer::now();
        selectionSort(arr,n);
        end = timer::now();
        duration += duration_cast<microseconds>(end-start);
    }
    cout << "Selection sort: " << duration.count()/100 << "us" << endl;

    //Time average HeapSort
    duration = duration_cast<microseconds>(end-end);
    for(int i = 0; i < 100; i++){
        populate(arr,n);
        start = timer::now();
        heapSort(arr,n);
        end = timer::now();
        duration += duration_cast<microseconds>(end-start);
    }
    cout << "Heap sort: " << duration.count()/100 << "us" << endl;

    return 0;
}
