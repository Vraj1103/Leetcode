class Solution {
public:
bool isPalindrome(int start, int end, string s){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }

    void p_partition(int index, string s,vector<string> &output,vector<vector<string>> &ans){
        if(index==s.size()){
            ans.push_back(output);
            return;
        }

        for(int i = index;i<s.size();i++){
            if(isPalindrome(index,i,s)){
                output.push_back(s.substr(index,i-index+1));
                p_partition(i+1,s,output,ans);
                output.pop_back();
            }
        }
    }     

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        p_partition(0,s,output,ans);
        return ans;
    }
};