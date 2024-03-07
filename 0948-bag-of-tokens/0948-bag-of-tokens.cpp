class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int count = 0,maxScore = 0;
        sort(tokens.begin(),tokens.end());
        int left = 0,right = tokens.size()-1;
        while(left<=right){
            if(tokens[left]<=power){
                power-= tokens[left++];
                count++;
                maxScore = max(maxScore,count);
            }
            else if(count>0){
                power+=tokens[right--];
                count--;
            }
            else 
                break;
        }
        return maxScore;
    }
};