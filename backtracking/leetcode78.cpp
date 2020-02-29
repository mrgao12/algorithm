#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 78 Subsets
 * Given a set of distinct integers, nums, 
 * return all possible subsets (the power set).
 * Note: The solution set must not contain duplicate subsets.
 * problem detail:https://leetcode-cn.com/problems/subsets
 * **/

class Solution {
    public:
        vector< vector< int > > subsets ( vector< int >& nums ) {
            vector< int > path;
            vector< vector< int > > res;
            backtrack ( 0, nums, path, res );
            return res;
        }

        void backtrack ( int depth, vector< int >& nums, vector< int >& path, vector< vector< int > >& res ) {
            if ( depth == nums.size() ) res.push_back ( path );
            else {
                path.push_back ( nums[depth] );
                backtrack ( depth+1, nums, path, res );

                path.pop_back();
                backtrack ( depth+1, nums, path, res );
            }
        }
};