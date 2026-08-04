class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
        }
        if(sum % 2 == 1){
            return false;
        }
        int find = sum / 2;
        // vector<vector<bool>>dp(n+1,vector<bool>(find+1,false));
        // for(int i = 0;i<=n ;i++){
        //     dp[i][0] = true;
        // }
        // for(int i = 1;i<=n;i++){
        //     for(int j = 1 ;j<=find;j++){
        //         if(nums[i-1] <= j){
        //             dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
        //         }
        //         else{
        //             dp[i][j] = dp[i-1][j];
        //         }
        //     }
        // }
        // return dp[n][find];
        vector<bool> dp(find+1,false);
        dp[0] = true;
        for(int x : nums){
            for(int i = find ; i >= x ;i--){
                dp[i] = dp[i] || dp[i - x];
            }
        }
        return dp[find];
    }
};