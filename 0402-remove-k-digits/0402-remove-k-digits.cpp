class Solution {
public:
    string removeKdigits(std::string num, int k) {
        stack<char> stack;

        for (char digit : num) {
            while (!stack.empty() && k > 0 && stack.top() > digit) {
                stack.pop();
                k--;
            }
            stack.push(digit);
        }

        while (k > 0 && !stack.empty()) {
            stack.pop();
            k--;
        }

        string result;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        reverse(result.begin(), result.end());

        size_t pos = result.find_first_not_of('0');
        cout<<pos;
        result = (pos == string::npos) ? "0" : result.substr(pos);

        return result;
    }
};
