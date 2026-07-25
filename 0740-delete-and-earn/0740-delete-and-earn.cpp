class Solution {
public:

    int solve(int value, vector<int>& points, vector<int>& dp) {

        if (value >= points.size()) {
            return 0;
        }

        if (dp[value] != -1) {
            return dp[value];
        }

        int take = points[value] + solve(value + 2, points, dp);

        int skip = solve(value + 1, points, dp);

        return dp[value] = max(take, skip);
    }

    int deleteAndEarn(vector<int>& nums) {

        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> points(maxi + 1, 0);
        vector<int> dp(maxi + 1, -1);

        for (int x : nums) {
            points[x] += x;
        }

        return solve(0, points, dp);
    }
};