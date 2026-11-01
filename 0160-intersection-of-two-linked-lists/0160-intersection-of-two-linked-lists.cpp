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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length1 = 0, length2= 0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1){
            length1++;
            temp1 = temp1->next;
        }
        while(temp2){
            length2++;
            temp2 = temp2->next;
        }
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        if(length1 > length2){
            int skip = length1-length2;
            while(skip-- !=0){
                ptr1 = ptr1->next;
            }
        }
        else if(length1 < length2){
            int skip = length2-length1;
            while(skip-- !=0){
                ptr2 = ptr2->next;
            }
        }
        while(ptr1 != ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};