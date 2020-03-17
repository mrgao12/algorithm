#include <iostream>
#include <stack>
using namespace std;

/**
 * leetcode 25 Reverse Nodes in k-Group
 * problem detail:https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
 * **/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//栈来实现
// class Solution {
//     public:
//         ListNode* reverseKGroup ( ListNode* head, int k ) {
//             stack<ListNode*> S;
//             ListNode* dummyHead =  new ListNode ( 0 );
//             ListNode* pre = dummyHead;

//             while ( head ) {
//                 int count = k;
//                 while ( count > 0 ) {
//                     if ( ! head ) break;
//                     S.push ( head );
//                     head = head->next;
//                     count--;
//                 }

//                 if ( count == 0 ) {
//                     while ( ! S.empty() ) {
//                         pre->next = S.top(); S.pop();
//                         pre = pre->next;
//                     }
//                 } else {
//                     stack<ListNode*> tmp;
//                     while ( ! S.empty() ) {
//                         tmp.push ( S.top() );
//                         S.pop();
//                     }

//                     while ( ! tmp.empty() ) {
//                         pre->next = tmp.top(); tmp.pop();
//                         pre = pre->next;
//                     }
//                 }
//             }
//             pre->next = NULL;
//             return dummyHead->next;
//         }
// };


class Solution {
    public:
        ListNode* reverseKGroup ( ListNode* head, int k ) {
            ListNode* dummyHead = new ListNode ( 0 );
            dummyHead->next = head;
            ListNode* last = dummyHead;
            ListNode* cur; ListNode* pre; ListNode* end;
            while ( true ) {
                int count = k;
                end = last;
                while ( count > 0 ) {
                    if ( ! end ) return dummyHead->next;
                    end = end->next; count--;
                }
                cur = last->next; pre = last->next->next;

                int step = 0;
                while ( step < k ) {
                    cur->next = end; step++;
                    end = cur; cur = pre; pre = pre->next;
                }
                last->next = end;
                while ( end->next != cur ) end = end->next;
                last = end;
            }
        }
};