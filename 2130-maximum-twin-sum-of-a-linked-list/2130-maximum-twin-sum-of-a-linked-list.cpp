/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<long long> sum;
        long long total = 0;
        while (head != NULL) {
            sum.push_back(head->val);
            head = head->next;
        }
        int i = 0, j = sum.size() - 1;

        while (i < j) {
            long long te_sum = sum[i] + sum[j];
            total = max(total, te_sum);
            i++;
            j--;
        }
        return total;
    }
};