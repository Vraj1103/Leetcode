class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size();
        int cols = box[0].size();
        
        for (int i = 0; i < rows; i++) {
            int emptyPos = cols - 1; 
            for (int j = cols - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    emptyPos = j - 1;
                } else if (box[i][j] == '#') {
                    swap(box[i][j], box[i][emptyPos]);
                    emptyPos--;
                }
            }
        }
        
        vector<vector<char>> rotatedBox(cols, vector<char>(rows));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rotatedBox[j][rows - 1 - i] = box[i][j];
            }
        }
        
        return rotatedBox;
    }
};
