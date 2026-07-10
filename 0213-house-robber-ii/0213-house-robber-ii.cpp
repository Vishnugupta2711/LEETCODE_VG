class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int ftlast = 0;
        int ftseclt = 0;
        int sdlast = 0;
        int sdseclt = 0;
        int fcurr , scurr;
        for(int i = n-2 ;i>=0;i--){
            fcurr = max(nums[i]+ftlast,ftseclt);
            ftlast = ftseclt;
            ftseclt = fcurr;
        }
        for(int i = n-1;i>=1;i--){
            scurr = max(nums[i]+sdlast,sdseclt);
            sdlast = sdseclt;
            sdseclt =  scurr;
        }
        return max(fcurr,scurr);
    }
};





// buttom-up approach
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1) return nums[0];
//         vector<int> dp1(n+2,-1);
//         vector<int> dp2(n+2,-1);
//         dp1[n] = dp1[n-1] = 0;
//         dp2[n] = dp2[n+1] = 0;
//         for(int i = n-2 ; i>=0 ; i--){
//             dp1[i] = max(nums[i] + dp1[i+2] , dp1[i+1]);
//         }
//         for(int i = n-1 ;i>=0 ; i--){
//             dp2[i] = max(nums[i] + dp2[i+2] , dp2[i+1]);
//         }
//         return max(dp1[0],dp2[1]);
//     }
// };



// top-down approach
// class Solution {
// public:
//     int find(int idx , int n ,vector<int>& nums,vector<int>& dp){
//         if(idx >= n)return 0;
//         if(dp[idx] != -1)return dp[idx];
//         return dp[idx] = max(nums[idx] + find(idx+2,n,nums,dp),find(idx+1,n,nums,dp));
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1)return nums[0];
//         vector<int> dp1(n+2,-1);
//         vector<int> dp2(n+2,-1);
//         return max(find(0,n-1,nums,dp1),find(1,n,nums,dp2));
//     }
// };