#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 19 Remove Nth Node From End of List
 * problem detail:https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 * **/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* removeNthFromEnd ( ListNode* head, int n  ) {
            ListNode* dummyHead = new ListNode ( 0 );
            dummyHead->next = head;
            ListNode* front = dummyHead; ListNode* rear = dummyHead;
            while ( n-- ) front = front->next;

            while ( front->next ) {
                front = front->next;
                rear = rear->next;
            }

            rear->next = rear->next->next;
            return dummyHead->next;
        }
};