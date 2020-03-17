#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 86 Partition List
 * problem detail:https://leetcode-cn.com/problems/partition-list/
 * **/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            if ( head == NULL ) return NULL;
            ListNode* sDummyHead = new ListNode(0);
            ListNode* bDummyHead = new ListNode(0);
            ListNode* s = sDummyHead;
            ListNode* b = bDummyHead;

            while ( head ) {
                if ( head->val < x ) {
                    s->next = head;
                    s = s->next;
                    head = head->next;
                } else {
                    b->next = head;
                    b = b->next;
                    head = head->next;
                }
            }
            b->next = NULL;
            s->next = bDummyHead->next;
            return sDummyHead->next;
        }
};