#include <iostream>
using namespace std;
int main(){
    int arr[] = {7,1,2,5,8,4,9,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    int ans = INT_MIN;
    int idx = -1;
    for (int i = 0; i <=n-k; i++)
    {
        int sum = 0;
        for (int j = i; j < i+k; j++)
        {
            sum+=arr[j];
        }
        cout<<sum<<" ";
        if(ans<sum){
            ans = sum;
            idx = i;
        }
    }
    cout<<endl;
    cout<<"Max sum subarray : "<<ans<<endl;
    cout<<"Max sum index : "<<idx<<endl;
    return 0;
}