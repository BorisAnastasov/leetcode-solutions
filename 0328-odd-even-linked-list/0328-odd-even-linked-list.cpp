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
    ListNode* oddEvenList(ListNode* head) {
        ListNode dummyOdd(0);
        ListNode dummyEven(0);
        ListNode* p1 = &dummyOdd;
        ListNode* p2 = &dummyEven;
        ListNode* curr = head;
        int count = 1;
        while(curr){
            if(count%2==0){
                p2->next = curr;
                p2 = p2->next;
            }
            else{
                p1->next = curr;
                p1 = p1->next;
            }
            curr = curr->next;
            count++;
        }
        p2->next = nullptr;
        p1->next = dummyEven.next;
        return dummyOdd.next;
    }
};