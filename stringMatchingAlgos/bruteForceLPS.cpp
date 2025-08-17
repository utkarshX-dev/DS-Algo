// longest prefix suffix
#include <iostream>
using namespace std;

int longestPrefixSuffix(string &s)
{
    int res = 0;
    int n = s.length();
    for (int i = 0; i < n - 1; i++)
    {
        int size = i + 1;
        bool valid = true;
        int j = 0;
        while (j < size)
        {
            if (s[j] != s[n - size + j])
            {
                valid = false;
                break;
            }
            else
            {
                j++;
            }
        }

        if (valid)
        {
            for (int k = 0; k < size; k++)
            {
                cout << s[k];
            }
            cout << endl;
            
            res = max(res, size);
        }
    }
    return res;
}

int main(){
    string s1 = "abcdeabcd";
    string s2 = "aaeaa";
    cout << longestPrefixSuffix(s1) << endl << endl;
    cout << longestPrefixSuffix(s2) << endl << endl;
    return 0;
}