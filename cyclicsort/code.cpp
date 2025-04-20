#include <iostream>
using namespace std;
int main(){
    int arr[6] = {4,1,6,2,5,3};
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    int idx = 0;
    int size = 6;
    while (idx<size)
    {
        if (arr[idx] = idx+1)
        {
            idx++;
        }
        else{
            int index = arr[idx]+1;
            swap(arr[idx],arr[index]);
        }
    }
    cout<<endl;
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}