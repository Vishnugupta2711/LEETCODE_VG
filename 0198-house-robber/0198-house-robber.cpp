class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0, b = 0;

        for (int money : nums) {
            int c = max(b, a + money);
            a = b;
            b = c;
        }

        return b;
    }
};