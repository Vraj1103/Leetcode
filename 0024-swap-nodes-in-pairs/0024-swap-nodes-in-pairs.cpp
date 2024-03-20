class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;

        int count = 0;

        while (curr != NULL && count < 2) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (next != NULL) {
            head->next = swapPairs(next);
        }
        return prev;
    }
};