struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements ( ListNode* head, int val ) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* q = dummyHead; ListNode* p;

        while ( p = q->next ) {
            if ( p->val == val ) {
                q->next = p->next;
                delete p;
            } else q = p;
        }
        return dummyHead->next;
    }
};