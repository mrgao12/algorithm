#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 90 Subsets II
 * Given a collection of integers that might contain duplicates,
 * nums, return all possible subsets (the power set).
 * Note: The solution set must not contain duplicate subsets.
 * problem detail:https://leetcode-cn.com/problems/subsets-ii
 * **/

class Solution {
    public:
        vector< vector< int > > subsetsWithDup ( vector< int >& nums ) {
            vector< int > path;
            vector< vector< int > > res;
            vector< bool > used ( nums.size() );
            sort ( nums.begin(), nums.end() );
            backtrack ( 0, used, nums, path, res );
            return res;
        }

        void backtrack ( int depth, vector< bool >& used, vector< int >& nums, vector< int >& path, vector< vector< int > >& res ) {
            if ( depth == nums.size() ) res.push_back ( path );
            else {
                path.push_back ( nums[depth] );
                if ( !(depth > 0 && nums[depth-1] == nums[depth] && used[depth-1] == false) ) {
                    used[depth] = true;
                    backtrack ( depth+1, used, nums, path, res );
                }

                used[depth] = false;
                path.pop_back();
                backtrack ( depth+1, used, nums, path, res );
            }
        }
};