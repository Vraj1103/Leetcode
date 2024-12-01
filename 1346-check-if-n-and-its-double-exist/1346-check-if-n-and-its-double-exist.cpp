class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;

        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (mp.find(arr[i] * 2) != mp.end()) {
                if (arr[i] * 2 != arr[i] || mp[arr[i] * 2] > 1) {
                    return true;
                }
            }

            if (arr[i] % 2 == 0 && mp.find(arr[i] / 2) != mp.end()) {
                if (arr[i] / 2 != arr[i] || mp[arr[i] / 2] > 1) {
                    return true;
                }
            }
        }

        return false;
    }
};
