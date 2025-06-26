#include <iostream>
#include <bits/stdc++.h>
using namespace std;
auto myComparator(int a, int b){
    return a >= b;
}
void print(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    vector<int> v = {1, 4, 1, 3, 5, 3};
    int x = 2, y = 4;
    sort(v.begin(), v.end(), myComparator);
    print(v);
    return 0;
}