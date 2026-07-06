class Solution {
public:
    int climbStairs(int n) {
        int last = 1;
        int nextlast = 0;
        for(int i = n-1;i>=0;i--){
            int curr = last + nextlast;
            nextlast = last ;
            last = curr;
        }
        return last;
    }
};









// top-down approach
// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> dp(n + 2);

//         dp[n] = 1;
//         dp[n + 1] = 0;

//         for (int i = n - 1; i >= 0; i--) {
//             dp[i] = dp[i + 1] + dp[i + 2];
//         }

//         return dp[0]; 
//     }
// };


// buttom-up approach 
// class Solution {
// public:
//     int help(int st , int n ,vector<int>& dp){
//         if(st == n )return 1;
//         if(st == n+1) return 0;
//         if(dp[st] != -1) return dp[st];
//         dp[st] = help(st+1,n,dp) + help(st+2,n,dp);
//         return dp[st];
//     } 
//     int climbStairs(int n) {
//         vector<int> dp(n+2,-1);
//         return help(0,n,dp);
//     }
// }; 