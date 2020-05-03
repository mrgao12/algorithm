#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        int val, size = 0;
        bool flag = true;
        void trav ( TreeNode* root ) {
            if ( ! root ) return;
            trav ( root->left );
            if ( ( size == 0 ) || ( root->val > val )  ) { val = root->val; size++; }
            else flag = false;
            trav ( root->right );
        }
        bool isValidBST ( TreeNode* root ) {
            if ( ! root ) return true;
            trav ( root );
            return flag;
        }
};