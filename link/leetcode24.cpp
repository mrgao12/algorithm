#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 24 Swap Nodes in Pairs
 * problem detail:https://leetcode-cn.com/problems/swap-nodes-in-pairs/
 * **/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// class Solution {
//     public:
//         ListNode* swapPairs ( ListNode* head ) {
//             if ( ! head || ! head->next ) return head;
//             ListNode* next = head->next;

//             head->next = swapPairs ( next->next );
//             next->next = head;

//             return next;
//         }
// };

class Solution {
    public:
        ListNode* swapPairs ( ListNode* head ) {
            ListNode* dummyHead = new ListNode ( 0 );
            dummyHead->next = head;
            ListNode* pre = dummyHead;
            while ( pre->next && pre->next->next ) {
                ListNode* front = pre->next->next;
                ListNode* rear = pre->next;

                pre->next = front;
                rear->next = front->next;
                front->next = rear;

                pre = rear;
            }

            return dummyHead->next;
        }
};