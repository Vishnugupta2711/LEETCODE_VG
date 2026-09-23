class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> used(26, false);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string st;

        for (char c : s) {
            int idx = c - 'a';
            freq[idx]--;

            if (used[idx])
                continue;

            while (!st.empty() &&
                   st.back() > c &&
                   freq[st.back() - 'a'] > 0) {

                used[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            used[idx] = true;
        }

        return st;
    }
};