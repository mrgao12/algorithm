
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* deleteDuplicates ( ListNode* head ) {
            if ( ! head || head->next == NULL ) return head;
            ListNode* p = head; ListNode* q;

            while ( ( q = p->next ) != NULL ) {
                if ( p->val != q->val ) p = q;
                else { p->next = q->next; delete q; }
            }

            return head;
        }
};