
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* deleteDuplicates ( ListNode* head ) {
            if ( ! head || head->next == NULL ) return head;
            ListNode* dummyHead = new ListNode ( -1 );
            dummyHead->next = head;
            ListNode* pp = dummyHead; ListNode* p = head; ListNode* q;
            int flag = 0;

            while ( ( q = p->next ) != NULL ) {
                if ( p->val != q->val ) {
                    if ( flag == 1 ) {
                        flag = 0;
                        pp->next = p->next; delete p;
                        p = q;
                    } else {
                        pp = p;
                        p = q;
                    }
                } else {
                    flag = 1;
                    p->next = q->next;
                    delete q;
                }
            }
            return dummyHead->next;
        }
};



class Solution {
    public:
        ListNode* deleteDuplicates ( ListNode* head ) {
            if ( ! head || head->next == NULL ) return head;
            ListNode* dummyHead = new ListNode ( -1 );
            dummyHead->next = head;
            ListNode* p = dummyHead; ListNode* q;

            while ( ( q = p->next ) != NULL && q->next ) {
                if ( p->next->val != q->next->val ) p = q;
                else {
                    while ( q->next && p->next->val == q->next->val ) q = q->next;
                    p->next = q->next;
                }
            } 
            return dummyHead->next;
        }
};