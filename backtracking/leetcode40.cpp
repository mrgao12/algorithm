#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 39 Combination Sum II
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 * Each number in candidates may only be used once in the combination.
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * problem detail:https://leetcode-cn.com/problems/combination-sum-ii
 * **/

class Solution {
    public:
        vector< vector< int > > combinationSum2( vector<int>& candidates, int target ) {
            vector< int > path;
            vector< vector< int > > res;
            vector< bool > used ( candidates.size() );
            sort ( candidates.begin(), candidates.end() );

            backtrack ( 0, used, candidates, target, path, res );

            return res;
        }

        void backtrack ( int depth, vector< bool >& used, vector<int>& candidates, int target, vector< int >& path, vector< vector< int > >& res ) {
            if ( target == 0 ) res.push_back ( path );
            else {
                for ( int i = depth; i < candidates.size(); i++ ) {
                    if ( i > 0 && candidates[i-1] == candidates[i] && ! used[i-1] ) continue;
                    if ( target >= candidates[i] ) {
                        used[i] = true;
                        path.push_back ( candidates[i] );
                        backtrack ( i+1, used, candidates, target-candidates[i], path, res );
                        path.pop_back();
                        used[i] = false;
                    }
                }
            }
        }
};