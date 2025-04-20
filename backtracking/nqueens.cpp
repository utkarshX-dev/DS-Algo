#include <iostream>
#include <vector>
using namespace std;

void display(const vector<vector<string>>& ans) {
    for (const auto& solution : ans) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }
}

bool canPlaceQueen(int row, int col, int n, const vector<vector<char>>& grid) {
    // Check if attack from top is possible
    for (int i = row - 1; i >= 0; i--) {
        if (grid[i][col] == 'Q') {
            return false;
        }
    }
    
    // Left diagonal check
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (grid[i][j] == 'Q') {
            return false;
        }
    }

    // Right diagonal check
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (grid[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void solve(int row, int n, vector<vector<char>>& grid, vector<vector<string>>& ans) {
    if (row == n) {
        vector<string> res;
        for (int i = 0; i < n; i++) {
            res.push_back(string(grid[i].begin(), grid[i].end()));
        }
        ans.push_back(res);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (canPlaceQueen(row, col, n, grid)) {
            grid[row][col] = 'Q';
            solve(row + 1, n, grid, ans);
            grid[row][col] = '.';
        }
    }
}

vector<vector<string>> nqueen(int n) {
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    vector<vector<string>> ans;
    solve(0, n, grid, ans);
    return ans;
}

int main() {
    int n = 4;  // You can change this to solve for any n
    vector<vector<string>> ans = nqueen(n);
    display(ans);
    return 0;
}
