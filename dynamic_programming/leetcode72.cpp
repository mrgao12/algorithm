#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 72 Edit Distance
 * Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
 * You have the following 3 operations permitted on a word:
 * 1. Insert a character
 * 2. Delete a character
 * 3. Replace a character
 * problem detail:https://leetcode-cn.com/problems/edit-distance
 * **/

class Solution {
    public:
        int minDistance( string word1, string word2 ) {
            int m = word1.length(), n = word2.length();
            vector < vector< int > > dp ( m+1, vector < int > ( n+1 ) );

            for ( int i = 0; i <= m; i++ ) {
                for ( int j = 0; j <= n; j++ ) {
                    if ( i == 0 ) dp[i][j] = j;
                    else if ( j == 0 ) dp[i][j] = i;
                    else {
                        if ( word1[i-1] == word2[j-1] ) dp[i][j] = dp[i-1][j-1];
                        else dp[i][j] = min ( dp[i-1][j-1], min ( dp[i-1][j], dp[i][j-1] ) ) + 1;
                    }
                }
            }

            return dp[m][n];
        }
};

int main()
{
    string a, b;
    Solution res;
    while ( cin>>a>>b ) {
        cout << res.minDistance ( a, b ) << endl;
    }
    system("pause");
    return 0;
}