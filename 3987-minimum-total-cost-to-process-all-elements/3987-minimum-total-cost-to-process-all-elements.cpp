class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        long long res = k ;
        long long op = 0;
        long long ans =0;
        for(int x : nums){
            if(res < x){
                long long t = (x - res + k -1LL)/k;
                long long a = t;
                long long b = 2LL * op + t + 1;
                if(a % 2 == 0){
                    a /= 2;
                }
                else{
                    b /= 2;
                }
                __int128 cost =  (__int128)a * (__int128)b;
                ans = (ans + (long long)(cost % MOD))% MOD;
                op += t;
                res += t * 1LL * k;
            }
            res -=x;
        }
        return ans % MOD;
    }
};