class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* prev = NULL;
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // if(fast)slow=slow->next;

        while (prev && slow) {
            if (prev->val != slow->val)
                return false;
            prev = prev->next;
            slow = slow->next;
        }
        return true;
    }
};