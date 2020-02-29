#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 46 Permutations
 * Given a collection of distinct integers, return all possible permutations.
 * problem detail:https://leetcode-cn.com/problems/permutations/
 * **/

class Solution {
    public:
        vector< vector< int > > permute( vector<int>& nums ) {
            vector< int > path;
            vector< vector< int > > res;
            vector< bool > used ( nums.size() );

            backtrack ( nums, used, path, res );
            return res;
        }

        void backtrack ( vector<int>& nums, vector<bool>& used, vector<int>& path, vector< vector< int > >& res ) {
            if ( path.size() == nums.size() ) res.push_back ( path );
            else {
                for ( int i = 0; i < nums.size(); i++ ) {
                    if ( ! used[i] ) {
                        path.push_back ( nums[i] );
                        used[i] = true;
                        backtrack ( nums, used, path, res );
                        used[i] = false;
                        path.pop_back();
                    }
                }
            }
        }
};