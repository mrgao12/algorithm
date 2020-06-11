struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
    public:
        int height ( TreeNode* p ) {
            if ( ! p ) return -1;
            return 1 + max ( height ( p->left ), height ( p->right ) );
        }
        bool isBalanced ( TreeNode* root ) {
            if ( ! root ) return true;
            if ( abs ( height ( root->left ) - height ( root->right ) ) > 1 ) return false;
            return ( isBalanced ( root->left ) && isBalanced ( root->right ) );
        }
};


class Solution {
    public:
        bool core ( TreeNode* p, int& height ) {
            if ( ! p ) {
                height = -1;
                return true;
            }
            
            int lh, rh;
            if ( core ( p->left, lh ) && core ( p->right, rh ) && abs ( lh - rh ) < 2 ) {
                height = max ( lh, rh ) + 1;
                return true;
            }
            return false;
        }
        bool isBalanced ( TreeNode* root ) {
            int height;
            return core ( root, height );
        }
};