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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }

        // Check whether k nodes are available
        ListNode* temp = head;
        int count = 0;

        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }

        // Less than k nodes -> don't reverse
        if (count < k) {
            return head;
        }

        // Reverse first k nodes
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        count = 0;

        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Recursively reverse remaining groups
        head->next = reverseKGroup(next, k);

        return prev;
    }
};
