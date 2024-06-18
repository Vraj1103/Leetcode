class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& pr, vector<int>& w) {
        long long res = 0, j = 0;
        int best = 0;
        vector<pair<int, int>> temp;

        for (int i = 0; i < d.size(); i++) {
            temp.emplace_back(d[i], pr[i]);
        }
        sort(temp.begin(), temp.end());
        sort(w.begin(),w.end());
        for (int work : w) {
            while (work >= temp[j].first && j < temp.size()) {
                best = max(best, temp[j++].second);
            }

            res += best;
        }
        return res;
    }
};