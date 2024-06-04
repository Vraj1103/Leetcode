class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for (auto x : s) {
            mp[x]++;
        }
        int count = 0;
        bool odd = false;
        for (auto x : mp) {
            if (x.second % 2 == 0)
                count += x.second;
            else {
                count += x.second - 1;
                odd = true;
            }
        }
        if (odd)
            return count + 1;
        else
            return count;
    }
};