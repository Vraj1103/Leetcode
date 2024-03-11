class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>st;
        for(char c : order){
            st[c]=0;
        }

        for(char a : s){
            if(st.find(a)!=st.end()){
                st[a]++;
            }
        }

        string sortedS;

        for(char c : order){
            sortedS.append(st[c],c);
        }    

        for(char a : s){
            if(st.find(a)==st.end()){
                sortedS.push_back(a);
            }
        }    
    return sortedS;
    }
};