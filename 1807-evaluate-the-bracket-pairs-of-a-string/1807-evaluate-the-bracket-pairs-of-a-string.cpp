class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (const auto& entry : knowledge) {
            mp[entry[0]] = entry[1];
        }

        string ans;

        for (int i = 0; i < (int)s.size(); ) {
            if (s[i] != '(') {
                ans += s[i];
                ++i;
                continue;
            }

            int j = i + 1;

            while (s[j] != ')') {
                ++j;
            }

            string key = s.substr(i + 1, j - i - 1);

            if (mp.count(key)) {
                ans += mp[key];
            } else {
                ans += '?';
            }

            i = j + 1;
        }

        return ans;
    }
};