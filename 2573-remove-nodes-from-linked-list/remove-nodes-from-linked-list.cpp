class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;

        while (curr != NULL) {

            while (!st.empty() && st.top()->val < curr->val) {
                st.pop();
            }

            st.push(curr);
            curr = curr->next;
        }

        vector<ListNode*> nodes;

        while (!st.empty()) {
            nodes.push_back(st.top());
            st.pop();
        }

        reverse(nodes.begin(), nodes.end());

        ListNode dummy(0);
        ListNode* tail = &dummy;

        for (auto node : nodes) {
            tail->next = node;
            tail = tail->next;
        }

        tail->next = NULL;

        return dummy.next;
    }
};