#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 216 Combination Sum III
 * Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 * Note:
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * problem detail:https://leetcode-cn.com/problems/combination-sum-iii
 * **/

class Solution {
    public:
        vector< vector< int > > combinationSum3 (int k, int n ) {
            vector< int > path;
            vector< vector< int > > res;

            backtrack ( 0, 1, k, n, path, res );
            return res;
        }

        void backtrack ( int depth, int start, int k, int n, vector< int >& path, vector< vector< int > >& res ) {
            if ( depth == k && n == 0 ) res.push_back ( path );
            else if ( depth > k || n < 0 ) return;
            else {
                for ( int i = start; i <= 9; i++ ) {
                    if ( n >= i ) {
                        path.push_back ( i );
                        backtrack ( depth+1, i+1, k, n-i, path, res );
                        path.pop_back();
                    }
                }
            }
        }
};