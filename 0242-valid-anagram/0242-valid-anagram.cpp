class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char,int> mp1,mp2;
        for(char x : s){
            mp1[x]++;
        }
        for(char x : t){
            mp2[x]++;
        }
        return mp1 == mp2;
    }
};