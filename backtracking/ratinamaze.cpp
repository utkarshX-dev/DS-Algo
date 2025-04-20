#include <iostream>
#include <vector>
using namespace std;
int ans;
bool canweGo(int i ,int j,int n,vector<vector<int>>&grid){
    return i>=0 && j>=0 && i < n && j < n && grid[i][j] == 0;
}
void f(vector<vector<int>>&grid,int n, int i,int j){
    if (i == n-1 and j == n-1)
    {
        ans++;
        return;
    }
    grid[i][j] = 2;// 2 means visited
    //left
    if (canweGo(i,j - 1,n,grid))
    {
        f(grid,n,i,j - 1);
    }
    //up
    if (canweGo(i - 1,j,n,grid))
    {
        f(grid,n,i - 1,j);
    }
    //right
    if (canweGo(i,j + 1,n,grid))
    {
        f(grid,n,i,j + 1);
    }
    //bottom
    if (canweGo(i + 1,j,n,grid))
    {
        f(grid,n,i + 1,j);
    }
    grid[i][j] = 0;
}
int ratinaMaze(vector<vector<int>>&grid, int n){
    ans = 0;
    f(grid,n,0,0);
    return ans;
}
int main(){
    vector<vector<int> > grid = {
        {0,0,1,0,0,1,0},
        {1,0,1,1,0,0,0},
        {0,0,0,0,1,0,1},
        {1,0,1,0,0,0,0},
        {1,0,1,1,0,1,0},
        {1,0,0,0,0,1,0},
        {1,1,1,1,0,0,0}
    };
    cout << ratinaMaze(grid,7);
    return 0;
}