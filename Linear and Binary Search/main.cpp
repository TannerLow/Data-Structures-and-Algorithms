#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
using namespace chrono;
typedef chrono::high_resolution_clock timer;
typedef uniform_int_distribution<int> random;

int linearSearch(int,int*,int);
int binarySearch(int,int*,int);

int main(){
    int n = 100000;

    //some overhead to generate random numbers
    random_device rd;
    default_random_engine eng {rd()};
    random dist(-1000, 1000);

    //Setting up the array
    int* a = new int[n];
    for(int i = 0; i < n; i++){
        a[i] = dist(eng);
    }
    sort(a,a+n);

    dist = random(0, n);//reset distribution range
    int key;
//linear search 10k
    auto start = timer::now();
    for(int i = 0; i < 10000; i++){
        key = a[dist(eng)];
        linearSearch(key,a,n);
    }
    auto end = timer::now();
    auto duration = duration_cast<microseconds>(end-start);
    auto tmp = duration;
    printf("Linear Search Time:%gns\n", (double)duration.count()/10.0);

//binary search 1m
    start = timer::now();
    for(int i = 0; i < 1000000; i++){
        key = a[dist(eng)];
        binarySearch(key,a,n);
    }
    end = timer::now();
    duration = duration_cast<microseconds>(end-start);
    printf("Binary Search Time:%gns\n", (double)duration.count()/1000.0);
//compare
    printf("Ratio = %.0f:1", 100.0*(double)tmp.count()/(double)duration.count());
    return 0;
}

int linearSearch(int n, int* arr, int arraySize){
    for(int i = 0; i < arraySize; i++)
        if(arr[i] == n)
            return i;
    return -1;
}

int binarySearch(int n, int* arr, int arraySize){
    int left = 0, right = arraySize-1;
    int mid;

    while(left <= right){
        mid = left + (right-left)/2;
        if(arr[mid] == n)
            return mid;
        else if(arr[mid] < n)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
