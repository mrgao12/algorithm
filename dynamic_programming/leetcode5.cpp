#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 5 Longest Palindromic Substring
 * Given a string s, find the longest palindromic substring in s. 
 * You may assume that the maximum length of s is 1000.
 * problem detail:https://leetcode-cn.com/problems/longest-palindromic-substring
 * **/

class Solution {
    public:
        string longestPalindrome( string s ) {
            int n = s.length(), start = 0, maxLen = 1;
            vector< vector< int > > dp ( n, vector< int >( n ) );

            for ( int i = 0; i < n; i++ ) {
                dp[i][i] = 1;
                if ( i < n-1 && s[i] == s[i+1] ) {
                    dp[i][i+1] = 1;
                    start = i;
                    maxLen = 2;
                }
            }

            for ( int l = 3; l <= n; l++ ) {
                for ( int i = 0; i < n - l + 1; i++ ) {
                    int j = l + i - 1;

                    if ( s[i] == s[j] && dp[i+1][j-1] ) {
                        dp[i][j] = 1;
                        start = i;
                        maxLen = l;
                    }
                }
            }

            return s.substr ( start, maxLen );
        }
};

int main()
{
    string a;
    Solution res;
    while ( cin>>a ) {
        cout << res.longestPalindrome ( a ) << endl;
    }
    system("pause");
    return 0;
}