#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int arr[] = {7, 1, 2, 5, 8, 4, 9, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int ans = INT_MIN;
    int prevSum = 0;
    int idx = 0;
    for (int i = 0; i < k; i++)
    {
        prevSum += arr[i];
    }
    ans = prevSum;
    int i = 1;
    int j = k;
    while (j < n)
    {
        int currSum = 0;
        currSum = prevSum + arr[j] - arr[i - 1];
        if (currSum>ans)
        {
            ans = currSum;
            idx = i;
        }
        prevSum = currSum;
        i++;
        j++;
    }
    cout << endl;
    cout << "Max sum subarray : " << ans << endl;
    cout << "Max sum subarray index : " << idx << endl;
    return 0;
}