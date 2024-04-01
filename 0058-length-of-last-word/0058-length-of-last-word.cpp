class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = 0;
        int i = s.size() - 1;
        cout << s.size();
        if (i == 0)
            return 1;

        while (s[i] == ' ') {
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            l++;
            i--;
        }

        return l;
    }
};