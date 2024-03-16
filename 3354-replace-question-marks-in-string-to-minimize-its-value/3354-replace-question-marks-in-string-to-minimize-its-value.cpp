class Solution {
public:
    string minimizeStringValue(string s) {
        unordered_map<char, int> mp(0);
        string ans, temp;

        for (auto& c : s) {
            if (c != '?') {
                mp[c]++;
            } else
                continue;
        }

        for (auto& c : s) {
            int cost = INT_MAX;
            if (c == '?') {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    cost = min(cost, mp[ch]);
                }
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (mp[ch] == cost) {
                        temp.push_back(ch);
                        mp[ch]++;
                        break;
                    }
                }
            }
        }
        sort(temp.begin(), temp.end());
        int i = 0;
        for (auto& c : s) {
            if (c != '?')
                ans.push_back(c);
            else {
                ans.push_back(temp[i]);
                i++;
            }
        }
        return ans;
    }
};