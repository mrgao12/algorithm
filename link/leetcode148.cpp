
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* merge ( ListNode*& p, ListNode* q ) {
            ListNode* dummyHead = new ListNode ( 0 );
            ListNode* head = dummyHead;
            while ( p || q ) {
                if ( ! p ) { head->next = q; break; }
                if ( ! q ) { head->next = p; break; } 
                if ( p->val <= q->val ) {
                    head->next = p;
                    p = p->next;
                    head = head->next;
                } else {
                    head->next = q;
                    q = q->next;
                    head = head->next;
                }
            }
            return dummyHead->next;
        }
        
        ListNode* midst ( ListNode* l ) {
            ListNode* dummyHead = new ListNode ( 0 );
            dummyHead->next = l;
            ListNode* slow = dummyHead; ListNode* fast = dummyHead;
            while ( fast && fast->next ) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }

        void mergeSort ( ListNode*& l ) {
            if ( l->next == NULL ) return;
            ListNode* mi = midst ( l );
            ListNode* p = l; ListNode* q = mi->next;
            mi->next = NULL;
            mergeSort ( p ); mergeSort ( q );
            l = merge ( p, q );
        }

        ListNode* sortList ( ListNode* head ) {
            if ( ! head || head->next == NULL ) return head;
            mergeSort ( head );
            return head;
        }
};