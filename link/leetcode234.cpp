
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    private:
        ListNode* front;
    public:
        bool recursion ( ListNode* cur ) {
            if ( cur ) {
                if ( ! recursion ( cur->next ) ) return false;
                if ( front->val != cur->val ) return false;
                front = front->next;
            }
            return true;
        }
        bool isPalindrome(ListNode* head) {
            front = head;
            return recursion ( head );
        }
};