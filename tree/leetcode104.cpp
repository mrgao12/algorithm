
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        int maxDepth ( TreeNode* root ) {
            if ( ! root ) return 0;
            return 1 + max( maxDepth ( root->left ), maxDepth ( root->right ) );
        }
};

class Solution {
    public:
        void dfs ( TreeNode* p, int depth, int& maxd ) {
            if ( maxd < depth ) maxd = depth;

            if ( p->left ) dfs ( p->left, depth + 1, maxd );
            if ( p->right ) dfs ( p->right, depth + 1, maxd );
        }
        int maxDepth ( TreeNode* root ) {
            int maxd = 0;
            if ( ! root ) return maxd;

            dfs ( root, 1, maxd );
        }
};