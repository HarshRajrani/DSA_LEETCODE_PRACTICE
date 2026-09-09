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
        ListNode*fast = head ; 
        ListNode*slow = head ; 

        while( fast && fast->next){

            slow = slow->next ; 
            fast = fast->next->next ; 

            if(fast == slow){

                ListNode*Newnode = head ; 

                while(Newnode != slow ){
                    slow = slow->next ; 
                    Newnode = Newnode->next ;
                }

                return Newnode ;
            }
        }

        return NULL;
    }
};