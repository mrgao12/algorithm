#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 92 Reverse Linked List II
 * problem detail:https://leetcode-cn.com/problems/reverse-linked-list-ii/
 * **/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* reverseBetween ( ListNode* head, int m, int n ) {
            if ( m == 1 ) return reverseN ( head, n );
            head->next = reverseBetween ( head->next, m-1, n-1 );
            return head;
        }

        ListNode* successor = NULL;
        ListNode* reverseN ( ListNode* head, int n ) {
            if ( n == 1 ) {
                successor = head->next;
                return head;
            }
            ListNode* last = reverseN ( head->next, n-1 );
            head->next->next = head;
            head->next = successor;
            return last;
        }
};