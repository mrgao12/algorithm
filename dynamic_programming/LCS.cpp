#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        int LCS ( string& a, string& b ) {
            int m = a.length(), n = b.length();
            vector< vector< int > >dp ( m+1, vector< int > ( n+1 ) );

            for ( int i = 1; i <= m; i++ ) {
                for ( int j = 1; j <= n; j++ ) {
                    if ( a[i-1] == b[j-1] ) dp[i][j] = dp[i-1][j-1] + 1;
                    else dp[i][j] = max ( dp[i-1][j], dp[i][j-1] );
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
        cout << res.LCS ( a, b ) << endl;
    }
    system("pause");
    return 0;
}