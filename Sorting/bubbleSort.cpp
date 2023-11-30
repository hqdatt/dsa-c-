// Does not require any additional memory space.
// Bubble sort has a time complexity of O(N2) which makes it very slow for large data sets.

#include <iostream> 
using namespace std;

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int arr[], int size){
    for(int n = 0; n < size; n++){
        for(int index = 0; index < size - n - 1; index++){
            if(arr[index+1]<arr[index]){
                swap(arr[index+1], arr[index]);
            }
        }
    }
}

int main(){
    int arr[] = {12, 5, 23, 8, 18, 29, 14};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Sorted Array: "<<endl;
    bubbleSort(arr, size);
    printArray(arr, size);
    return 0;
}