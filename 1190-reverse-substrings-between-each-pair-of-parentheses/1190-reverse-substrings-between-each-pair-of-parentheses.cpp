class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stk; // Stack to track opening parenthesis indices

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i); // Push opening parenthesis index onto the stack
            } else if (s[i] == ')') {
                int start = stk.top(); // Get the index of the matching opening
                                       // parenthesis
                stk.pop(); // Pop the opening parenthesis index from the stack
                reverse(s.begin() + start + 1,
                        s.begin() + i); // Reverse the substring
            }
        }

        // Construct the final string (excluding parentheses)
        string result;
        for (char c : s) {
            if (c != '(' && c != ')') {
                result += c;
            }
        }

        return result;
    }
};
