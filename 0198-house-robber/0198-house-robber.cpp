class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2,0);
        dp[n]=0;
        dp[n+1]=0;
        for(int i = n-1 ;i>= 0;i--){
            dp[i] = max(nums[i]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }
};



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