
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        bool hasCycle ( ListNode *head ) {
            if ( ! head || head->next == NULL ) return;
            ListNode* slow = head; ListNode* fast = head;

            while ( slow && fast && fast->next ) {
                slow = slow->next;
                fast = fast->next->next;
                if ( slow == fast ) return true;
            }
            return false;
        }
};