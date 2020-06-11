#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        vector<TreeNode*> core ( int start, int end ) {
            vector<TreeNode*> treeArray;
            if ( end < start ) {
                treeArray.push_back ( ( TreeNode* ) NULL );
                return treeArray;
            }
            for ( int i = start; i <= end; i++ ) {
                vector<TreeNode*> left = core ( start, i - 1 );
                vector<TreeNode*> right = core ( i + 1, end );

                for ( auto lt : left ) {
                    for ( auto rt : right ) {
                        TreeNode* root = new TreeNode ( i );
                        root->left = lt;
                        root->right = rt;
                        treeArray.push_back ( root );
                    }
                }
            }
            return treeArray;
        }
        vector<TreeNode*> generateTrees ( int n ) {
            if ( n == 0 ) return vector<TreeNode*>();
            return core ( 1, n );
        }
};