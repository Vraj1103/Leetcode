class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxlen = 0;
        vector<int> charCount(26, 0);

        int left = 0, right = 0;

        while (right < s.length()) {
            charCount[s[right] - 'a']++;
            while (charCount[s[right] - 'a'] > 2) {
                charCount[s[left] - 'a']--;
                left++;
            }
            maxlen = std::max(maxlen, right - left + 1);
            right++;
        }

        return maxlen; 
     }
};