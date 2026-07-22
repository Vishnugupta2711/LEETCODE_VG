class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);

        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }

        return (int)dp[amount];
    }
};
// buttom-up approch
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();

//         vector<vector<unsigned long long>> dp(n + 1,vector<unsigned long long>(amount + 1, 0));

//         for (int i = 0; i <= n; i++)
//             dp[i][0] = 1;

//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= amount; j++) {

//                 if (coins[i - 1] > j)
//                     dp[i][j] = dp[i - 1][j];
//                 else
//                     dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
//             }
//         }

//         return (int)dp[n][amount];
//     }
// };

// top- down approach
// class Solution {
// public:
//     int find(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {

//         if (amount == 0)
//             return 1;

//         if (idx < 0)
//             return 0;

//         if (dp[idx][amount] != -1)
//             return dp[idx][amount];

//         if (coins[idx] > amount)
//             return dp[idx][amount] = find(idx - 1, amount, coins, dp);

//         return dp[idx][amount] =
//             find(idx, amount - coins[idx], coins, dp) +
//             find(idx - 1, amount, coins, dp);
//     }

//     int change(int amount, vector<int>& coins) {

//         int n = coins.size();

//         vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

//         return find(n - 1, amount, coins, dp);
//     }
// };


// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         vector<unsigned long long> dp(amount + 1, 0);

//         dp[0] = 1;

//         for (int coin : coins) {
//             for (int i = coin; i <= amount; i++) {
//                 dp[i] += dp[i - coin];
//             }
//         }

//         return (int)dp[amount];
//     }
// };






// recursion
// class Solution {
// public:
//     int find(int idx, int amount,vector<int>& coins){
//         if(amount == 0) return 1;
//         if(idx < 0) return 0 ; 
//         if(coins[idx] > amount){
//             return find(idx-1,amount,coins);
//         }
//         else{
//             return find(idx,amount-coins[idx],coins) + find(idx-1,amount,coins); 
//         }
//     }
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         return find(n-1,amount,coins);
//     }
// };
