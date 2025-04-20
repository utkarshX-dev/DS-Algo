#include <iostream>
using namespace std;
void print(int *arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void recSelectionSort(int *arr,int size,int index){
    if(index == size-1){
        return;
    }
    int minIndex = index;
    for(int j=index+1;j<size;j++){
        if(arr[minIndex] > arr[j]){
            minIndex = j;
        }
    }
    swap(arr[index],arr[minIndex]);
    recSelectionSort(arr,size,index+1);
}
void selectionSort(int *arr,int size){
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for(int j=i+1;j<size;j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }}
        swap(arr[i],arr[minIndex]);
    }}

void bubbleSort(int *arr,int size){
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
        
    }  
}
void recBubbleSort(int *arr,int size){
    if(size == 1) return;
    for(int i=0;i<size-1;i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    recBubbleSort(arr,size-1);
}
void insertionSort(int *arr,int size){
    for(int i=1;i<size;i++){
        for (int j = i; j >0; j--)
        {
            if(arr[j]<arr[j-1]){
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
            else{
                break;
            }
        }
    }
}

void recInsertionSort(int *arr,int size,int index){
    if(index == size) return ;
    for (int j = index; j >0; j--)
        {
            if(arr[j]<arr[j-1]){
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
            else{
                break;
            }
        }
        recInsertionSort(arr,size,index + 1);
}
int main(){
    
    int arr1[] = {1, 9, 5, 6, 3, 2, 0};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "\nOriginal Array 1 :\n";
    print(arr1, size1);
    selectionSort(arr1, size1);
    cout << "\nSorted by Selection Sort:\n";
    print(arr1, size1);

    int arr2[] = {10, 7, 8, 9, 1, 5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "\nOriginal Array 2 :\n";
    print(arr2, size2);
    recSelectionSort(arr2, size2, 0);
    cout << "\nSorted by Recursive Selection Sort:\n";
    print(arr2, size2);

    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "\nOriginal Array 3 :\n";
    print(arr3, size3);
    bubbleSort(arr3, size3);
    cout << "\nSorted by Bubble Sort:\n";
    print(arr3, size3);

    int arr4[] = {5, 3, 8, 6, 2, 4, 7, 1};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    cout << "\nOriginal Array 4 :\n";
    print(arr4, size4);
    recBubbleSort(arr4, size4);
    cout << "\nSorted by Recursive Bubble Sort:\n";
    print(arr4, size4);

    int arr5[] = {9, 5, 1, 4, 3};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    cout << "\nOriginal Array 5 :\n";
    print(arr5, size5);
    insertionSort(arr5, size5);
    cout << "\nSorted by Insertion Sort:\n";
    print(arr5, size5);

    int arr6[] = {20, 15, 12, 30, 5};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    cout << "\nOriginal Array 6 :\n";
    print(arr6, size6);
    recInsertionSort(arr6, size6, 0);
    cout << "\nSorted by Recursive Insertion Sort:\n";
    print(arr6, size6);

    return 0;
}
