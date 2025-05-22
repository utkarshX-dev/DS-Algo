#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string printlcs(string s1, string s2, vector<vector<int>>& dp){
    int n = dp.size();
    int m = dp[0].size();
    int i = n, j = m;
    string temp = "";
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            temp.push_back(s1[i - 1]);
            i--, j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(temp.begin(), temp.end());
    return temp;
}
int longestCommonSubsequence(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << "longest common subsequence : " << printlcs(s1, s2, dp) << endl;
        return dp[n][m];
    }
int main(){
    cout << longestCommonSubsequence("bdgek", "abcde");
    return 0;
}
