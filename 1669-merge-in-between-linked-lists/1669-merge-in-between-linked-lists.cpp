class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
     ListNode* curr = list1;
     int count = 0;
     ListNode* curr2 = list2;
     while(curr!=NULL && count<a-1){
        curr = curr->next;
        count++;
     }
     ListNode *end = curr;
     while(count<b+1){
        curr = curr->next;
        count++;
     }
     ListNode* tail = curr;
     end->next = curr2;

     while(curr2->next!=NULL){
        curr2 = curr2->next;
    }

     curr2->next = tail;

     return list1;
    }
};