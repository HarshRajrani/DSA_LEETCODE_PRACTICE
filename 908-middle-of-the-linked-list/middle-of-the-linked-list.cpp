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
    ListNode* middleNode(ListNode* head) {
        
        int length = 0 ; 
        ListNode* curr = head ; 

        while(curr  != NULL){
            length++ ; 
            curr = curr->next ;
        }

        int middle  = length/2 ; 

        curr = head ; 

        for(int i = 0 ; i< middle ; i++){
            curr = curr->next ; 
        }

        return curr ; 
    }
};