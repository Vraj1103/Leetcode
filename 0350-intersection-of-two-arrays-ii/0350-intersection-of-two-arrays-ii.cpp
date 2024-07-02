class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i=nums1.size()-1; i>=0; i--){
            mp[nums1[i]] ++;
            nums1.pop_back();
        }
        for(int i=nums2.size()-1; i>=0; i--){
            if(mp.find(nums2[i]) != mp.end() and mp[nums2[i]] > 0){
                ans.push_back(nums2[i]);
                mp[nums2[i]] --;
            }
            nums2.pop_back();
        }
        return ans;
    }
};