#include <iostream>
#include <vector>
using namesapce std;

/**
 * leetcode 120 Triangle
 * Given a triangle, 
 * find the minimum path sum from top to bottom. 
 * Each step you may move to adjacent numbers on the row below.
 * problem detail:https://leetcode-cn.com/problems/triangle
 * **/

class Solution {
    public:
        int minimumTotal( vector< vector< int > >& triangle ) {
            int n = triangle.size(), minPath = INT_MAX;
            if ( n == 1 ) return triangle[0][0];
            vector< vector< int > > dp ( n, vector< int > ( n ) );
            dp[0][0] = triangle[0][0];

            for ( int i = 1; i < n; i++ ) {
                for ( int j = 0; j <= i; j++ ) {
                    if ( j == 0 ) dp[i][j] = triangle[i][j] + dp[i-1][j];
                    else if ( j == i ) dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                    else dp[i][j] = min ( dp[i-1][j], dp[i-1][j-1] ) + triangle[i][j];

                    if ( i == n-1 && dp[i][j] < minPath ) minPath = dp[i][j]; 
                }
            }
            return minPath;
        }
};