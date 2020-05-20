#include <iostream>

using namespace std;

//Helper print function for arrays
template <typename T>
void print(const T *arr, const int &size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

template <typename T>
void insertionSort(T *arr, const int &size){
    for(int i = 1; i < size; i++){
        int j = i;
        for( ; j > 0 and arr[j] < arr[j-1]; j--){
            T temp   = arr[j  ];
            arr[j  ] = arr[j-1];
            arr[j-1] = temp;
        }
    }
}

int main(){
    int a[8] = {6, 3, 4, 2, 8, 1, 5, 7};
    print(a, 8); //Before Sort
    insertionSort(a, 8);
    print(a, 8); //After Sort
    return 0;
}
