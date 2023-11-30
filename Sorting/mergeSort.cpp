#include <iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int arr[], int start, int mid, int end){
    int len_left = mid - start + 1;
    int len_right = end - mid;

    int* left = new int[len_left];
    int* right = new int[len_right];

    for(int i = 0; i<len_left; i++){
        left[i] = arr[start + i];
    }
    for(int i = 0; i<len_right; i++){
        right[i] = arr[mid + 1 + i];
    }
    
    int i = 0, j = 0, k = start;
    while(i<len_left && j<len_right){
        if(left[i]<=right[j]){
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while(i<len_left){
        arr[k++] = left[i++];
    }
    while(i<len_right){
        arr[k++] = right[i++];
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int start, int end){
    int mid = start + (end - start)/2;
    if(start<end){
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main(){
    int arr[] = {12, 5, 23, 8, 18, 29, 14, 20, 16};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Sorted Array: "<<endl;
    mergeSort(arr, 0, size - 1);
    printArray(arr, size);
    return 0;
}