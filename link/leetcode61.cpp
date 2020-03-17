#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 61 Rotate List
 * problem detail:https://leetcode-cn.com/problems/rotate-list/
 * **/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if ( head == NULL ) return NULL;
        int n = 0; ListNode* test = head;
        while ( test ) {
            n++;
            test = test->next;
        }
        k = k % n;
        if ( k == 0 ) return head;
        ListNode* pre; ListNode* tail;

        pre = head; tail = head;
        while ( k-- ) tail = tail->next;

        while ( tail->next ) {
            pre = pre->next;
            tail = tail->next;
        }

        tail->next = head;
        test = pre->next;
        pre->next = NULL;

        return test;
    }
};