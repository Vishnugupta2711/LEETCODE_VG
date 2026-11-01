class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.empty()) return 0;
        long long mn = *min_element(nums.begin(), nums.end());
        long long total = 0;
        for (int x : nums) total += (long long)x - mn;
        return static_cast<int>(total);
    }
};