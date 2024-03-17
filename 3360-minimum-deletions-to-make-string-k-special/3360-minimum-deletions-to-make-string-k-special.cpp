class Solution {
public:
    int minimumDeletions(std::string word, int k) {
        unordered_map<char, int> charCountMap;
        for (char character : word) {
            charCountMap[character] = charCountMap.count(character) ? charCountMap[character] + 1 : 1;
        }
        vector<int> charCounts;
        for (auto const& [character, count] : charCountMap) {
            charCounts.push_back(count);
        }
        sort(charCounts.begin(), charCounts.end(), std::greater<int>());
        int minDeletions = INT_MAX;
        for (size_t i = 0; i < charCounts.size(); ++i) {
            int currentCount = charCounts[i];
            int deletions = 0;
            for (size_t j = 0; j < charCounts.size(); ++j) {
                if (charCounts[j] > currentCount + k) {
                    deletions += (charCounts[j] - (currentCount + k));
                } else if (charCounts[j] < currentCount) {
                    deletions += charCounts[j];
                }
            }
            minDeletions = min(minDeletions, deletions);
        }
        return minDeletions;
    }
};
