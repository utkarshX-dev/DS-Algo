#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n = 3;
    vector<vector<char>>res(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j + i >= n - 1){
                res[i].push_back('*');
            }else{
                res[i].push_back(' ');
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}