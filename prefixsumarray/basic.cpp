#include <iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 1; i < n; i++)
    {
        arr[i] = arr[i] + arr[i-1];
    }
    cout<<"Prefix Sum array : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    bool partition = false;
    for (int i = 0; i < n; i++)
    {
        if(2*arr[i] == arr[n-1]){
            partition = true;
            break;
        }
    }
    cout<<endl;
    if(partition){
        cout<<"Partition of array is possible";
    }
    else{
        cout<<"Partition of array is not possible";
    }
    return 0;
}