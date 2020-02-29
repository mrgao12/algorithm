#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * leetcode 22 Generate Parentheses
 * Given n pairs of parentheses, 
 * write a function to generate all combinations of well-formed parentheses.
 * problem detail:https://leetcode-cn.com/problems/generate-parentheses
 * **/

class Solution {
    public:
        vector<string> generateParenthesis( int n ) {
            vector<string> res;
            if ( n == 0 ) return res;
            backtrack ( res, "", n, n );
            return res;
        }

        void backtrack ( vector<string>& res, string s, int left, int right ) {
            if ( left == 0 && right == 0 ) res.push_back ( s );
            if ( left > 0 ) backtrack ( res, s+"(", left-1, right );
            if ( left < right && right > 0 ) backtrack ( res, s+")", left, right-1 );
        }

};