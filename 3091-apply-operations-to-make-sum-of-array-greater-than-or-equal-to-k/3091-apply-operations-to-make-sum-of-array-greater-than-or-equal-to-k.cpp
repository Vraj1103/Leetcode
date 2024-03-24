class Solution {
public:
    int minOperations(int target) {   
    if (target == 1)
            return 0;
        
        int minOps = INT_MAX;
        for (int i = 1; i <= (target / 2); i++) {
            int temp = (int)ceil((double)target / i);
            int operations = (i - 1) + (temp - 1);
            minOps = min(operations, minOps);
        }
        
        return minOps;
    }
};