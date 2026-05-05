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
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || !head->next || k == 0) {
            return head;
        }

        int L = 1;

        ListNode* Tails = head;

        while (Tails->next != NULL) {
            Tails = Tails->next;
            L++;
        }

        k = k % L;

        int remaining = L - k;

        if (k == 0) {
            return head;
        }

        // circular

        Tails->next = head;

        ListNode* newTails = head;

        for (int i = 1; i < remaining; i++) {

            newTails = newTails->next;
        }

        ListNode* newhead = newTails->next;
        newTails->next = NULL;

        return newhead;
    }
};