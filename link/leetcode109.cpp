#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 109 Convert Sorted List to Binary Search Tree
 * problem detail:leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/
 * **/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST ( ListNode* head ) {
        if ( head == NULL ) return NULL;
        ListNode* mid = findMidElement ( head );

        TreeNode* root = new TreeNode ( mid->val );
        root->left = sortedListToBST ( head );
        root->right = sortedListToBST ( mid->next );
        return root;
    }
    ListNode* findMidElement ( ListNode* head ) {
        ListNode* pre; ListNode* slow; ListNode* fast;
        slow = fast = head;
        while ( fast && fast->next ) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return slow;
    }
};