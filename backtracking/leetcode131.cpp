#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/**
 * leetcode 131 Palindrome Partitioning
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return all possible palindrome partitioning of s.
 * problem detail:https://leetcode-cn.com/problems/palindrome-partitioning
 * **/

class Solution {
    public:
        vector< vector< string > > partition ( string s ) {
            vector< string > path;
            vector< vector< string > > res;

            backtrack ( 0, s, path, res );
            return res;
        }

        void backtrack ( int depth, string s, vector< string >& path, vector< vector< string > >& res ) {
            if ( depth == s.length() ) res.push_back ( path );
            else {
                for ( int l = 1; l <= s.length() - depth + 1; l++ ) {
                    string sub = s.substr ( depth, l );
                    if ( isPalindrome ( sub ) ) {
                        path.push_back ( sub );
                        backtrack ( depth + l, s, path, res );
                        path.pop_back();
                    }
                }
            }
        }

        bool isPalindrome ( string str ) {
            string revStr = str;
            reverse ( revStr.begin(), revStr.end() );
            if ( str == revStr ) return true;
            else return false;
        }
};