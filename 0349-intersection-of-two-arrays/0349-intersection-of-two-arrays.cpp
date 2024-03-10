class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
         std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> set2(nums2.begin(), nums2.end());
        
        std::vector<int> result;
        for (int num : set1) {
            if (set2.count(num)) {
                result.push_back(num);
            }
        }
        
        return result;
    }
};