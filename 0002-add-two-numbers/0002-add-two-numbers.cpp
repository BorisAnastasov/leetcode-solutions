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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int accumilate = 0;
        ListNode* head = nullptr;
        ListNode* prevNode = nullptr;
        while (p1 && p2) {
            int sum = p1->val + p2->val + accumilate;
            accumilate = 0;
            ListNode* node = new ListNode(0);
            if (!head) {
                head = node;
                prevNode = node;
            } else {
                prevNode->next = node;
                prevNode = prevNode->next;
            }
            if (sum < 10) {
                node->val = sum;
            } else {
                node->val = sum-10;
                accumilate +=1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        while(p1){
            int sum = p1->val+accumilate;
            accumilate = 0;
            ListNode* node = new ListNode(0);
            if (!head) {
                head = node;
                prevNode = node;
            } else {
                prevNode->next = node;
                prevNode = prevNode->next;
            }
            if (sum < 10) {
                node->val = sum;
            } else {
                node->val = sum-10;
                accumilate +=1;
            }
            p1 = p1->next;
        }

        while(p2){
            int sum = p2->val+accumilate;
            accumilate = 0;
            ListNode* node = new ListNode(0);
            if (!head) {
                head = node;
                prevNode = node;
            } else {
                prevNode->next = node;
                prevNode = prevNode->next;
            }
            if (sum < 10) {
                node->val = sum;
            } else {
                node->val = sum-10;
                accumilate +=1;
            }
            p2 = p2->next;
        }
        if(accumilate){
            prevNode->next = new ListNode(1);
        }
        return head;
    }
};