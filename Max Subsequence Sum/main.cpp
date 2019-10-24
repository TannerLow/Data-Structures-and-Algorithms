#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <ctime>

using namespace std;

int MSS(int* arr, int size){
    int sum = 0, mss = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
        if(sum < 1) sum = 0;
        if(sum > mss) mss = sum;
    }
    return mss;
}

int slowMSS(int* arr, int left, int right){
    if(left < right){
        int median = (left+right)/2;
        int mssL = slowMSS(arr, left, median),
            mssR = slowMSS(arr, median+1, right);
        int sumL = 0, sumR = 0,
            maxL = 0, maxR = 0;
            
        for(int i = median+1; i <= right; i++)
            if((sumR += arr[i]) > maxR) maxR = sumR;
        for(int i = median; i >= left; i--)
            if((sumL += arr[i]) > maxL) maxL = sumL;
            
        return max({mssL, mssR, maxL+maxR});
    }
    return arr[left];
}

int main(){
    int n;
    cout << "Input value, n: ";
    cin >> n;
    
    int a[n];
    srand(time(0));
    for(int i = 0; i < n; i++)
        cout << (a[i] = rand() % 201 - 100) << " ";
    cout << endl;
    
    cout << "Proper   MSS method: " << MSS(a,n) << endl;
    cout << "Terrible MSS method: " << slowMSS(a,0,n-1) << endl;
    return 0;
}
