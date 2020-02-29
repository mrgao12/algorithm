#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 47 Permutations II
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * problem detail:https://leetcode-cn.com/problems/permutations-ii
 * **/

class Solution {
    public:
        vector< vector< int > > permuteUnique( vector<int>& nums ) {
            vector< int > path;
            vector< vector< int > > res;
            vector< bool > used ( nums.size() );
            sort ( nums.begin(), nums.end() );
            backtrack ( nums, used, path, res );
            return res;
        }

        void backtrack ( vector<int>& nums, vector<bool>& used, vector<int>& path, vector< vector< int > >& res ) {
            if ( path.size() == nums.size() ) res.push_back ( path );
            else {
                for ( int i = 0; i < nums.size(); i++ ) {
                    if ( i > 0 && nums[i-1] == nums[i] && ! used[i-1] ) continue;
                    else {
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
        }
};