class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL) {
            fast = fast->next;
            if (fast->next != NULL) {
                fast = fast->next;
            }
            slow = slow->next;
            if (fast == slow && slow != NULL) {
                slow = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            };
        }
        return NULL;
    }
};