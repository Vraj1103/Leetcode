class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int> v;
        for(auto i:h) v.push_back(i);
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<h.size();i++)
        {
            if(v[i]!=h[i]) ans++;
        }
        return ans;
    }
};