#include <iostream>
#include<vector>
using namespace std;
int main(){
    int rows = 3;
    int cols = 4;
    int row = 0;
    int col = 0;
    vector<int>ans;
    vector<vector<int>>matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    while(col < cols - 1){
        ans.push_back(matrix[row][col]);
        col++;
    }

    while(row < rows - 1){
        ans.push_back(matrix[row][col]);
        rows++;
    }

    while(col >= 0){
        ans.push_back(matrix[row][col]);
        col--;
    }
    while(row >= 0){
        ans.push_back(matrix[row][col]);
        rows--;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i] << " ";
    }
    
    return 0;
}