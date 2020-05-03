#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int getHeight ( TreeNode* p ) {
        if ( !p ) return 0;
        return 1 + max ( getHeight ( p->left ), getHeight ( p->right ) );
    }
    bool isBalanced ( TreeNode* root ) {
        if ( ! root ) return true;
        if ( abs ( getHeight ( root->lc ) - getHeight ( root->rc ) ) <= 1 ) {
            return isBalanced ( root->left ) && isBalanced ( root->right );
        } else {
            return false;
        }
    }
};