class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points,
                            vector<vector<int>>& queries) {
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int count = 0;
            float dis = 0;
            for (int j = 0; j < points.size(); j++) {
                int x = pow((queries[i][0] - points[j][0]), 2);
                int y = pow((queries[i][1] - points[j][1]), 2);
                dis = sqrt(x + y);
                if (dis <= queries[i][2]) {
                    count++;
                }
            }
            ans.push_back(count);
            count = 0;
        }
        return ans;
    }
};