class Solution {
public:
    int help(int st , int n ,vector<int>& dp){
        if(st == n )return 1;
        if(st == n+1) return 0;
        if(dp[st] != -1) return dp[st];
        dp[st] = help(st+1,n,dp) + help(st+2,n,dp);
        return dp[st];
    } 
    int climbStairs(int n) {
        vector<int> dp(n+2,-1);
        return help(0,n,dp);
    }
};