#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//backtracking approach
class Solution {
public:
    vector<vector<int>>res;
    void f(int i, vector<int>& nums, vector<int>& temp) {
        if (i == nums.size()) {
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        f(i + 1, nums, temp);
        temp.pop_back();
        f(i + 1, nums, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp = {};
        f(0, nums, temp);
        return res;
    }
};
//iterative approach
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>res;
        res.push_back({});
        for(int i = 0; i < n; i++){
            int currSize = res.size();
            int val = nums[i];
            for(int j = 0; j < currSize; j++){
                vector<int>temp = res[j];
                temp.push_back(val);
                res.push_back(temp);
            }
        }
        return res;
    }
};