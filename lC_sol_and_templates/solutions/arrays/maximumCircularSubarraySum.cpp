#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    pair<int, int> kadaneMaxSum(vector<int>& nums){
        int totalSum = 0;
        int currSum = 0;
        int maxSum = INT_MIN;
        for(int& x : nums){
            currSum += x;
            maxSum = max(maxSum, currSum);
            if(currSum < 0){
                currSum = 0;
            }
            totalSum += x;
        }
        return {totalSum, maxSum};
    }
    int kadaneMinSum(vector<int>& nums){
        int currSum = 0, minSum = 0;
         for(int& x : nums){
            currSum += x;
            minSum = min(minSum, currSum);
            if(currSum > 0){
                currSum = 0;
            }
        }
        return minSum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        auto curr = kadaneMaxSum(nums);
        int totalSum = curr.first, normalSum = curr.second;
        int minSum = kadaneMinSum(nums);
        if(totalSum == minSum) return normalSum;
        return max(totalSum - minSum, normalSum);
    }
};