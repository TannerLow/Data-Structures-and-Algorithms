#include <iostream>

using namespace std;

int missing(int*,int);

int main()
{
    //square root
    int in = 0;
    cin >> in;
    while(in != -1){

        int l = 1, r = in, m;
        while(l <= r){
            m = l + (r-l)/2;
            if(m*m >= in && (m-1)*(m-1) < in) break;
            else if(m*m > in) r = m-1;
            else l = m+1;
        }
        cout << m << endl;
        
        cin >> in;
    }
    //Find smallest missing element
    int n = 0;
    cin >> n;
    while(n != -1){
        int* arr = new int[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        cout << missing(arr,n) << endl;
        
        cin >> n;
    }
    return 0;
}

int missing(int* arr, int n){
    int l = 0, r = n-1, m;
    while(l <= r){
        m = l + (r-l)/2;
        if(arr[m] == m && arr[m+1] != m+1) return m+1;
        else if(arr[m] > m) r = m-1;
        else l = m+1;
    }
    if(arr[l] > l) return 0;
    else return n;
}