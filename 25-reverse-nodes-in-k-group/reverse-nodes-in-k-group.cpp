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
        if(head == NULL || k == 1) return head ; 

        ListNode*dummy = new ListNode(0) ;
        dummy->next = head ; 

        ListNode*prevgroup = dummy ;

        while(true){
            ListNode*kth = prevgroup ;

            for(int i = 0 ; i< k && kth != NULL ; i++)
                kth = kth->next ;

                if(kth == NULL) break ;
            ListNode*groupNext = kth->next ; 
            ListNode*prev = groupNext ; 
            ListNode*curr = prevgroup->next ; 

            while( curr != groupNext){
                ListNode* next = curr->next ; 
                curr->next = prev ; 
                prev = curr;
                curr = next ; 
            }
            ListNode*temp = prevgroup->next ; 
            prevgroup->next = kth ; 
            prevgroup = temp; 
        }
        return dummy->next ;
    }
};