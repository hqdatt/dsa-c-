// Insertion sort is efficient for small data values
// The average case time complexity of the Insertion sort is O(N^2)

#include <iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertsionSort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        while (i>=0 && arr[i+1]<arr[i]){
                swap(arr[i+1],arr[i]);
                i--;
        }
    }
}

int main(){
    int arr[] = {12, 5, 23, 8, 18, 29, 14};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Sorted Array: "<<endl;
    insertsionSort(arr, size);
    printArray(arr, size);
    return 0;
}
