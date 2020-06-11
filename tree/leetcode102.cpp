#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        void dfs ( TreeNode* p, vector< vector< int > >& levels, int level ) {
            if ( level == levels.size() ) levels.push_back ( vector< int >() );

            levels[level].push_back ( p->val );

            if ( p->left ) dfs ( p->left, levels, level + 1 );
            if ( p->right ) dfs ( p->right, levels, level + 1 );
        }
        vector< vector< int > > levelOrder( TreeNode* root ) {
            vector< vector< int > > levels;
            if ( root == NULL ) return levels;

            dfs ( root, levels, 0 );
            return levels;
        }
};


class Solution {
    public:
        vector< vector< int > > levelOrder( TreeNode* root ) {
            vector< vector< int > > levels;
            if ( ! root ) return levels;

            queue< TreeNode* > Q; Q.push ( root );

            while ( ! Q.empty() ) {
                int size = Q.size();
                levels.push_back ( vector< int > () );
                while ( size-- ) {
                    TreeNode* p = Q.front(); Q.pop();
                    levels.back().push_back ( p->val );

                    if ( p->left ) Q.push ( p->left );
                    if ( p->right ) Q.push ( p->right );
                }
            }
            return levels;
        }
};