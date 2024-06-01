class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;

        for(int i = 0;i<s.size()-1;i++){
            int ans = abs(s[i]-s[i+1]);
            score+=ans;
        }
        return score;
    }
};