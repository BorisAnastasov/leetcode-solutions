/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if (!head || !head->next) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast){
            slow = slow->next;
            fast = fast->next;
            if(!fast) return nullptr;
            fast = fast->next;
            if(slow == fast){
                ListNode* curr = head;
                while(curr != slow){
                    curr = curr->next;
                    slow = slow->next;
                }
                return curr;
            }
        }
        
        return nullptr;
    }
};