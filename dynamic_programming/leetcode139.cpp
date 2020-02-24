#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 139 Word Break
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 * Note:
 * The same word in the dictionary may be reused multiple times in the segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * problem detail:https://leetcode-cn.com/problems/word-break
 * **/

class Solution {
    public:
        bool wordBreak( string s, vector<string>& wordDict ) {
            int n = s.length();
            vector< bool > dp ( n+1 );
            dp[0] = true;

            for ( int i = 1; i <= n; i++ ) {
                for ( int j = 0; j < i; j++ ) {
                    int len = i - j;
                    if ( dp[j] && isContain ( wordDict, s.substr ( j, len ) ) ) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        bool isContain ( vector<string>& wordDict, string s ) {
            for ( int i = 0; i < wordDict.size(); i++ ) {
                if ( wordDict[i] == s ) return true;
            }
            return false;
        }
};