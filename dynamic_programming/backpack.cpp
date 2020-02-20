#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int backpack ( vector< int >& v, vector< int >& w, int c ) {
            int n = w.size();
            vector < vector < int > > dp ( n+1, vector < int > ( c+1 ) );

            for ( int i = 1; i <= n; i++ ) {
                for ( int j = 1; j <= c; j++ ) {
                    if ( j < w[i-1] ) dp[i][j] = dp[i-1][j];
                    else dp[i][j] = max ( dp[i-1][j-w[i-1]] + v[i-1], dp[i-1][j] );
                }
            }

            return dp[n][c];
        }
};

int main()
{
    Solution res;
    int V[] = { 12, 3, 10, 3, 6 };
    int W[] = { 5, 4, 7, 2, 6 };
    int c = 15;
    vector<int> v ( V, V+5 );
    vector<int> w ( W, W+5 );
    cout << res.backpack ( v, w, c ) << endl;
    system("pause");
    return 0;
}