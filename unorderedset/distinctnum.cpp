// class Solution {
// int reverse(int n){
//     int num = 0;
//     while(n!=0){
//         int digit = n%10;
//         num = num*10 + digit;
//         n = n/10;
//     }
//     return num;
// }
// public:
//     int countDistinctIntegers(vector<int>& nums) {
//         unordered_set<int>s;
//         for(int i = 0 ; i<nums.size();i++){
//             s.insert(nums[i]);
//         }
//         for(int i =0 ;i<nums.size();i++){
//             s.insert(reverse(nums[i]));
//         }
//         return s.size();
//     }
// };