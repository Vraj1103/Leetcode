class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        int count = 0;
        int win = 0;
        int mx = 0;
        for (int i = 0; i < c.size(); i++) {
            if (g[i] == 0) {
                count += c[i];
            } else if (i < m) {
                count += c[i];
            }
        }
        mx = count;

        for (int i = m; i < c.size(); i++) {
            count+=c[i]*g[i];
            count-=c[i-m]*g[i-m];
            mx = max(mx,count);
        }
        return mx;
    }
};