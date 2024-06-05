class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        unordered_map<char, int> mp;

        // Initialize the map with the first word's characters
        for (char c : words[0]) {
            mp[c]++;
        }

        // Compare with other words
        for (int i = 1; i < words.size(); i++) {
            unordered_map<char, int> mp2;
            for (char c : words[i]) {
                if (mp[c] > 0) {
                    mp2[c]++;
                    mp[c]--;
                }
            }
            mp = mp2;
        }

        // Collect the common characters
        for (auto &m : mp) {
            while (m.second-->0) {
                ans.push_back(string(1, m.first));
            }
        }
        return ans;
    }
};
