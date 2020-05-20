struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        // ListNode* flip ( ListNode* p ) {
        //     ListNode* dummyHead = new ListNode ( 0 );
        //     ListNode* q;
        //     while ( p ) {
        //         q = p->next;
        //         p->next = dummyHead->next;
        //         dummyHead->next = p;
        //         p = q;
        //     }
        //     return dummyHead->next;
        // }

        ListNode* flip ( ListNode* p ) {
            ListNode* pre = NULL;
            ListNode* q;
            while ( p ) {
                q = p->next;
                p->next = pre;
                pre = p;
                p = q;
            }
            return pre;
        }

        // ListNode* flip ( ListNode* p ) {
        //     if ( ! p || p->next == NULL ) return p;

        //     ListNode* newHead = flip ( p->next );
        //     p->next->next = p;
        //     p->next = NULL;
        //     return newHead;
        // }

        ListNode* merge ( ListNode* A, ListNode* B ) {
            ListNode* dummyHead = new ListNode ( 0 );
            ListNode* head = dummyHead;
            int i = 0;
            while ( A && B ) {
                if ( i % 2 == 0 ) { head->next = A; head = head->next; A = A->next; }
                else { head->next = B; head = head->next; B = B->next; }
                i++;
            }
            A ? head->next = A : head->next = B;
            return dummyHead->next;
        }

        void reorderList( ListNode* head ) {
            if ( ! head || head->next == NULL ) return;
            ListNode* slow = head; ListNode* fast = head;
            while ( slow && fast && fast->next ) {
                slow = slow->next;
                fast = fast->next->next;
            }

            ListNode* A = head;
            ListNode* B = slow->next; slow->next = NULL;
            B = flip ( B );
            head = merge ( A, B );
        }
};