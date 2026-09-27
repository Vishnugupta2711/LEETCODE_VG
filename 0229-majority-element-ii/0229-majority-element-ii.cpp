class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int lt = n/3;
        vector<int> ans;
        unordered_map<int,int> freq;
        for(int x : nums){
            freq[x]++;
        }
        for(auto x :freq ){
            if(lt < x.second){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};