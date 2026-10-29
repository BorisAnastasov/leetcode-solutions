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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next) {
            if(slow->val != fast->val){
                slow->next = fast;
                slow = fast;
            }
            fast = fast->next;
        }
        if(slow->val != fast->val){
                slow->next = fast;
            }
            else{
                slow->next = nullptr;
            }
        return head;
    }
};