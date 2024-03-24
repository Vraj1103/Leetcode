class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res=0, n=s.size();
        for(int i=0; i<n; i++) {
            vector<int> mp(256, 0);
            for(int j=i; j<n; j++) {
                mp[s[j]]++;
                
                if(mp[s[j]]>2) {
                    res=max(res, j-i);
                    break;
                }
                else {
                    res=max(res, j-i+1);
                }
            }
            mp.clear();
        }
        return res;
    }
};