#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 221 Maximal Square
 * Given a 2D binary matrix filled with 0's and 1's, 
 * find the largest square containing only 1's and return its area.
 * problem detail:https://leetcode-cn.com/problems/maximal-square/
 * **/

class Solution {
    public:
        int maximalSquare( vector< vector< char > >& matrix ) {
            int m = matrix.size(), maxLen = 0, n;
            if ( m == 0 ) return 0;
            else n = matrix[0].size();
            vector< vector< int > > dp ( m, vector< int > ( n ) );

            for ( int i = 0; i < m; i++ ) {
                for ( int j = 0; j < n; j++ ) {
                    if ( matrix[i][j] == '1' ) {
                        if ( i > 0 && j > 0 ) {
                            dp[i][j] = min ( dp[i-1][j-1], min ( dp[i-1][j], dp[i][j-1] )  ) + 1;
                        } else dp[i][j] = 1;
                    }

                    if ( dp[i][j] > maxLen ) maxLen = dp[i][j];
                }
            }

            return maxLen * maxLen;
        }
};