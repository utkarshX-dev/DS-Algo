#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int arr[] = {2, -3, 4, 4, -7, -1, 4, -2, 6};
    vector<int> ans;
    int size = sizeof(arr) / sizeof(arr[0]);
    int negIdx = -1;
    int k = 4;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            negIdx = i;
            break;
        }
    }
    if (negIdx == -1)
        ans.push_back(0);
    else
        ans.push_back(arr[negIdx]);

    int j = k;
    int i = 1;
    while (j < size)
    {
        if (negIdx >= i && negIdx <= j)
            ans.push_back(arr[negIdx]);
        else
        {
            negIdx = -1;
            for (int x = i; x <= j; x++)
            {
                if (arr[x] < 0)
                {
                    negIdx = x;
                    break;
                }
            }
            if (negIdx == -1)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(arr[negIdx]);
            }
        }
        i++, j++;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}