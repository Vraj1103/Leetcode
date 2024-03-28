class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return NULL;
        if(head->next==NULL)return head;
        ListNode* prev = head;
        ListNode* temp = head->next;
        while (temp != NULL) {
            if (prev->val == temp->val) {
                while (temp != NULL && prev->val == temp->val) {
                    temp = temp->next;
                }
                prev->next = temp;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};