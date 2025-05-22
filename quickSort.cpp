#include <iostream>
#include <vector>
using namespace std;

// T.C : nlogn
//Worst Case : 0(n ^ 2) if pivot is repeatedly smallest or largest problem of array

// first time n operations
// second time n - 1 operation
// ........... 0 
// Total operations : n + (n - 1) + (n - 2) + (n - 3) + ............... + 1 +  0 = 
// T.C: n(n - 1)/2 or n ^ 2
// S.C: O(1)

void print(vector<int>& arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int partition(int s, int e, vector<int>& arr){
    int pivot = arr[e];
    int idx = s - 1;
    for (int j = s; j < e; j++)
    {
        if(arr[j] <= pivot){
            idx++;
            swap(arr[idx] , arr[j]);
        }
    }

    //for pivot index
    swap(arr[idx + 1], arr[e]);
    return idx + 1;
    return idx;
}
void quickSort(vector<int>& arr, int s, int e){
    if(s >= e) return;
    else{
        int pivIdx = partition(s, e, arr);
        quickSort(arr, s, pivIdx - 1);
        quickSort(arr, pivIdx + 1, e);
    }
}
int main(){
    vector<int>arr = {12, 31, 35, 8, 32, 7};
    int s = 0, e = arr.size() - 1;
    cout << "Before quicksort : " << endl;
    print(arr);

    quickSort(arr, s, e);
    cout << "After quick Sort : ";
    print(arr);
    
    return 0;
}