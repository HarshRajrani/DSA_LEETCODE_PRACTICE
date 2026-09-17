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
    ListNode* partition(ListNode* head, int x) {

        ListNode* smalldummy = new ListNode(0);
        ListNode* largedummy = new ListNode(0);

        ListNode* small = smalldummy;
        ListNode* large = largedummy;
        ListNode* curr = head;

        while(curr != NULL){

            if( curr->val < x){
                small->next = curr;
                small = small->next ;
            }
            else{
                large->next = curr ; 
                large = large->next ; 
            }

            curr = curr->next ;
        }
        large->next = NULL ;
        small->next = largedummy->next ;

        return smalldummy->next ;
    }
};