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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == NULL)
            return {-1,-1};
        vector<int> temp;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int i = 1;
        while (curr->next) {
            if (curr->val > prev->val && curr->val > curr->next->val) {
                temp.push_back(i);
            } else if (curr->val < prev->val &&
                       curr->val < curr->next->val) {
                temp.push_back(i);
            }
                prev = curr;
                curr = curr->next;
                i++;
            
        }

        sort(temp.begin(),temp.end());
        // for(auto x : temp){
        //     cout<<x<<endl;
        // }
        if(temp.size()<2)return {-1,-1};


        vector<int>ans;
        int mini = INT_MAX;
        for(int i = 0;i<temp.size()-1;i++){
            mini = min(mini,temp[i+1]-temp[i]);
        }
        ans.push_back(mini);
        ans.push_back(temp[temp.size()-1]-temp[0]);
        return ans;
    }
};