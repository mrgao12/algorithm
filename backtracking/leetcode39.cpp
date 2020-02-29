#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 39 Combination Sum
 * Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 * The same repeated number may be chosen from candidates unlimited number of times.
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * problem detail:https://leetcode-cn.com/problems/combination-sum 
 * **/

class Solution {
    public:
        vector< vector< int > > combinationSum( vector<int>& candidates, int target ) {
            vector< int > path;
            vector< vector< int > > res;
            backtrack ( 0, candidates, target, path, res );
            return res;
        }

        void backtrack ( int depth, vector<int>& candidates, int target, vector< int >& path, vector< vector< int > >& res ) {
            if ( target == 0 ) res.push_back ( path );
            else {
                for ( int i = depth; i < candidates.size(); i++ ) {
                    if ( target >= candidates[i] ) {
                        path.push_back ( candidates[i] );
                        backtrack ( i, candidates, target-candidates[i], path, res );
                        path.pop_back();
                    }
                }
            }
        }
};