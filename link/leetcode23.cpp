#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 23 Merge k Sorted Lists
 * problem detail:https://leetcode-cn.com/problems/merge-k-sorted-lists/
 * **/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* mergeKLists ( vector<ListNode*>& lists ) {
            return mergeCore ( 0, lists.size(), lists );
        }
        ListNode* mergeCore ( int lo, int hi, vector<ListNode*>& lists ) {
            if ( hi - lo < 2 ) return lists[lo];
            int mi = ( lo + hi ) / 2;
            ListNode* left = mergeCore ( lo, mi, lists );
            ListNode* right = mergeCore ( mi, hi, lists );
            return merge ( left, right );
        }
        ListNode* merge ( ListNode* left, ListNode* right ) {
            if ( left == NULL ) return right;
            else if ( right == NULL ) return left;
            else if ( left->val < right->val ) {
                left->next = merge ( left->next, right );
                return left;
            } else {
                right->next = merge ( left, right->next );
                return right;
            }
        }
};