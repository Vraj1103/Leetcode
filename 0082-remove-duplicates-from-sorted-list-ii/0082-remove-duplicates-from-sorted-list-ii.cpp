class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> mp;
        ListNode* curr = head;
        while (curr) {
            mp[curr->val]++;
            curr = curr->next;
        }
        ListNode* temp = new ListNode(0);
        ListNode* head2 = temp;
        for (auto& x : mp) {
            if (x.second == 1) {
                temp->next = new ListNode(x.first);
                temp = temp->next;
            }
        }
        return head2->next;
    }
};