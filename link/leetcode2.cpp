#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 2 Add Two Numbers
 * problem detail:https://leetcode-cn.com/problems/add-two-numbers/
 * **/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers ( ListNode* l1, ListNode* l2 ) {
            ListNode* dummyHead = new ListNode ( 0 );
            ListNode* cur = dummyHead; 
            int carry = 0;
            while ( l1 || l2 ) {
                int x = l1 ? l1->val : 0;
                int y = l2 ? l2->val : 0;

                int s = x + y + carry;
                carry = s / 10;
                cur->next = new ListNode ( s % 10 );
                cur = cur->next;

                if ( l1 ) l1 = l1->next;
                if ( l2 ) l2 = l2->next;
            }

            if ( carry > 0 ) cur->next = new ListNode ( carry );
            return dummyHead->next;
        }
};