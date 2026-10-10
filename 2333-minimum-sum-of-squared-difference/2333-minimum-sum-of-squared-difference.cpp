class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long budget = (long long)k1 + k2;

        const int MAXV = 100000;
        vector<long long> freq(MAXV + 2, 0);

        for (int i = 0; i < n; i++) {
            freq[abs(nums1[i] - nums2[i])]++;
        }

        for (int d = MAXV; d > 0 && budget > 0; d--) {
            if (freq[d] == 0) continue;
            long long moved = min(budget, freq[d]);
            freq[d] -= moved;
            freq[d - 1] += moved;
            budget -= moved;
        }
        long long ans = 0;
        for (long long d = 1; d <= MAXV; d++) {
            ans += freq[d] * d * d;
        }
        return ans;
    }
};