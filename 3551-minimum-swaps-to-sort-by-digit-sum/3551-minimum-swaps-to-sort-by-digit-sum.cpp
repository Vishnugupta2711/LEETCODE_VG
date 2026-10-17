
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        auto digitSum = [](int x) {
            int sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            return sum;
        };

        vector<pair<int, int>> order;
        order.reserve(n);

        for (int x : nums) {
            order.emplace_back(digitSum(x), x);
        }

        sort(order.begin(), order.end());

        unordered_map<int, int> target;
        target.reserve(n * 2);

        for (int i = 0; i < n; ++i) {
            target[order[i].second] = i;
        }

        vector<bool> seen(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (seen[i]) continue;

            int cur = i;
            int length = 0;

            while (!seen[cur]) {
                seen[cur] = true;
                cur = target[nums[cur]];
                ++length;
            }

            if (length > 1) {
                swaps += length - 1;
            }
        }

        return swaps;
    }
};
