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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* curr=head;
        ListNode* leftNode = nullptr;
        for(int i = 1;i < left;i++){
            leftNode = curr;
            curr = curr->next;
        }

        ListNode* chainHead = curr;
        ListNode* ptr = curr;
        ListNode* prev = leftNode;

        for(int i = left;i <= right;i++){
            ListNode* temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp; 
        }

        chainHead->next = ptr;

        if(leftNode) {
            leftNode->next = prev;
            return head;
        }

        return prev;

    }
};