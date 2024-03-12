class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.length();
        int sum=0;
        for(int i=0;i<n;i++){
            int j=(columnTitle[i]-'A')+1;
            sum=sum*26+j;
        }
        return sum;
    }
};