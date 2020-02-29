#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 77 Combinations
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 * problem detail:https://leetcode-cn.com/problems/combinations
 * **/

class Solution {
    public:
        vector< vector< int > > combine(int n, int k) {
            vector< int > path;
            vector< vector< int > > res;

            backtrack ( 1, n, k, path, res );
            return res;
        }

        void backtrack ( int depth, int n, int k, vector< int >& path, vector< vector< int > >& res ) {
            if ( depth > k ) res.push_back ( path );
            else {
                for ( int i = depth; i <= n; i++ ) {
                    path.push_back ( i );
                    backtrack ( depth+1, n, k, path, res );
                    path.pop_back();
                }
            }
        }
};