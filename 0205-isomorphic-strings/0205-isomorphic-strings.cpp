class Solution {
public:
    bool isIsomorphic(string s, string t) {
        set<char>st;
        unordered_map<char,char>mp;

        if(s.size()!=t.size())return false;

        for(int i = 0;i<s.size();i++){
            st.insert(t[i]);

            if(mp[s[i]]>0){
                if(mp[s[i]]!=t[i])return false;
            }
            else
                mp[s[i]]=t[i];
            
            if(st.size()!=mp.size())return false;
        }
        return true;
    }
};