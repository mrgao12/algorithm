#include <iostram>
#include <vector>
using namespace std;

/**
 * leetcode 516 Longest Increasing Subsequence
 * Given a string s, find the longest palindromic subsequence's length in s.
 * You may assume that the maximum length of s is 1000.
 * problem detail:https://leetcode-cn.com/problems/longest-palindromic-subsequence
 * **/

class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            int n = s.length();
            vector< vector< int > >dp ( n, vector<int> ( n ) );

            for ( int i = n - 1; i >= 0; i-- ) {
                dp[i][i] = 1;
                if ( i < n - 1 ) {
                    if ( s[i] == s[i+1] ) dp[i][i+1] = 2;
                    else dp[i][i+1] = 1;
                }
                for ( int j = i + 2; j < n; j++ ) {
                    if ( s[i] == s[j] ) dp[i][j] = dp[i+1][j-1] + 2;
                    else dp[i][j] = max ( dp[i+1][j], dp[i][j-1] );
                }
            }

            return dp[0][n-1];
        }
};