
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* search ( ListNode* head, int n, int e ) {
            ListNode* p = head; ListNode* q;
            while ( 0 <= n-- ) {
                q = p;
                if ( e <= ( p = p->next )->val ) break;
            }
            return q;
        }

        void insertA ( ListNode* p, int e ) {
            ListNode* x = new ListNode ( e );
            x->next = p->next;
            p->next = x;
        }

        ListNode* insertionSortList ( ListNode* head ) {
            if ( ! head || head->next == NULL ) return head;
            ListNode* dummyHead = new ListNode ( 0 );
            dummyHead->next = head;
            ListNode* q = dummyHead; ListNode* p;
            int r = 0;

            while ( ( p = q->next ) != NULL ) {
                insertA ( search ( dummyHead, r, p->val ), p->val );
                while ( q->next != p ) q = q->next;
                q->next = p->next; delete p; r++;
            }
            return dummyHead->next;
        }
};