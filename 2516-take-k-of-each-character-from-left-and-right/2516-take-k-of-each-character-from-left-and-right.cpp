class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> freq(3, 0);
        for (auto& x : s) {
            freq[x - 'a']++;
        }

        for (auto& x : freq) {
            x -= k;
            if (x < 0)
                return -1;
        }
        vector<int> curr(3, 0);
        int length = 0;
        int r = 0, l = 0;
        while (r < s.size()) {
            curr[s[r] - 'a']++;
            while (curr[s[r] - 'a'] > freq[s[r] - 'a']) {
                curr[s[l] - 'a']--;
                l++;
            }
            length = max(length, r - l + 1);
            r++;
        }
        return s.size() - length;
    }
};