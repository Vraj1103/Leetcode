class Solution {
public:
    void solve(int idx, string s, string word, vector<string>& ans,
               unordered_set<string> st) {
        if (idx == s.length()) {
            ans.push_back(word);
            return;
        }
        string newword;
        for (int i = idx + 1; i <= s.size(); i++) {
            string temp = s.substr(idx, i - idx);
            if (st.find(temp) != st.end()) {
                if (!word.empty()) {
                    newword = word + " " + temp;
                } else
                    newword = temp;
                solve(i, s, newword, ans, st);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wd) {
        unordered_set<string> st(wd.begin(), wd.end());
        string word;
        vector<string> ans;
        solve(0, s, word, ans, st);
        return ans;
    }
};