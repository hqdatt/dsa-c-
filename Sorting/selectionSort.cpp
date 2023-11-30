// Works well with small datasets.
// Selection sort has a time complexity of O(n^2) in the worst and average case.

#include <iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int arr[], int size){
    for(int n = 0; n < size - 1; n++){
        int minIndex = n;
        for(int index = n+1; index<size; index++){
            if(arr[index]<arr[minIndex]){
                minIndex = index;
            }
        }
        if(minIndex!=n){
            swap(arr[n], arr[minIndex]);
        }
    }
}

int main(){
    int arr[] = {17, 9, 32, 5, 28, 3};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Sorted Array: "<<endl;
    selectionSort(arr, size);
    printArray(arr, size);
    return 0;
}