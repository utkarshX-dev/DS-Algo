#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int b;
    int k;
    cin >> b >> k;
    int a[k];
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        cin >>a[i]; 
    }
    
    int i = 0;

    while (k - 1 != 0)
    {
        sum += a[i++] * pow(b,k--);
    }
    
    if (sum % 2 == 0)
    {
        cout << "even";
    }
    else cout << "odd";
    
    return 0;
}