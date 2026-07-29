class Solution {
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
       int next1 = 0 ; 
       int next2 = 0;
       int res ;
       for(int i = n-1;i>=0;i--){
            res = max(nums[i] + next2, next1);
            next2 = next1;
            next1 = res;
       }
       return next1;
    }
};

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n+2,0);
//         for(int i = n-1 ; i >=0;i--){
//             int take = nums[i] + dp[i+2];
//             int skip = dp[i+1];
//             dp[i] = max(take,skip);
//         }
//         return dp[0];
//     }
// };





// space-optimization
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         int last = 0;
//         int seclast = 0;
//         int curr;
//         for(int i = n-1 ;i >=0;i--){
//             curr = max(nums[i]+last , seclast);
//             last = seclast;
//             seclast = curr;
//         }
//         return seclast;
//     }
// };




// buttom-up approach
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n+2,0);
//         dp[n]=0;
//         dp[n+1]=0;
//         for(int i = n-1 ;i>= 0;i--){
//             dp[i] = max(nums[i]+dp[i+2],dp[i+1]);
//         }
//         return dp[0];
//     }
// };



// top-down approach 
// class Solution {
// public:
//     int find(int idx ,vector<int>& nums,int n,vector<int>& dp){
//         if(idx >= n) return 0;
//         if(dp[idx] != -1) return dp[idx];
//         return dp[idx] = max((nums[idx] +find(idx+2,nums,n,dp)),find(idx+1,nums,n,dp));
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n+2,-1);
//         return find(0,nums,n,dp);
//     }
// };