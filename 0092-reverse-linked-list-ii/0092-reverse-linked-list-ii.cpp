
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        ListNode* current = head;
        ListNode* previous = NULL;
        // left = left -1;
        // int diff = left - right - 1;
        int count = 1;
        while(count!=left){
            previous = current;
            current = current->next;
            count++;
        }
        
        ListNode* forward = NULL;
        ListNode* curr = current->next;
        ListNode* prev = current;

        while(count<right){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        if(previous!=NULL)previous->next = prev;
        else head = prev;

        if(current!=NULL)current->next = curr;

        return head;
    }
};