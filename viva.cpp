#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool Checkprecedence(string& a, string& b) {
    if (a.length() + 1 != b.length()) return false;

    int i = 0, j = 0;
    bool mismatchFound = false;

    while (i < a.length() && j < b.length()) {
        if (a[i] == b[j]) {
            i++;
        } else {
            if (mismatchFound) return false; 
            mismatchFound = true;
        }
        j++;
    }
    return true;
}

int main(){
    vector<string> arr = {"a","b","ba","bca","bdaa","bdcaj"};
    // sort(arr.begin(), arr.end(), [](const string &a, const string &b) {
    //     if (a.length() == b.length())
    //         return a < b; 
    //     return a.length() < b.length(); 
    // });
    cout << Checkprecedence(arr[4], arr[5]);
    return 0;
}
   
// =["xbc","pcxbcf","xb","cxbc","pcxbc"]