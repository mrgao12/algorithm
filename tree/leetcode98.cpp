#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        void travInorder ( TreeNode* root, vector<int>& range ) {
            if ( ! root ) return;

            travInorder ( root->left, range );
            range.push_back ( root->val );
            travInorder ( root->right, range );
        }
        bool isValidBST ( TreeNode* root ) {
            vector<int> range;
            travInorder ( root, range );

            for ( int i = 1; i < range.size(); i++ ) {
                if ( range[i] <= range[i-1] ) return false;
            }
            return true;
        }
};