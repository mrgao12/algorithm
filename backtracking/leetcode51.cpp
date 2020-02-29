#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 51 N-Queens
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 * problem detail:https://leetcode-cn.com/problems/n-queens
 * **/

class Solution {
    public:
        vector< vector< string > > solveNQueens ( int n ) {
            vector< vector< bool > > flag ( 3, vector< bool > ( 2*n ) );
            vector< vector< string > > res;

            string str ( n, '.' );
            vector< string > path ( n, str );
            backtrack ( n, 0, flag, path, res );
            return res;
        }

        void backtrack ( int n, int depth, vector< vector< bool > >& flag, vector< string >& path, vector< vector< string > >& res ) {
            if ( depth == n ) res.push_back ( path );
            else {
                for ( int i = 0; i < n; i++ ) {
                    if ( ! flag[0][i] && ! flag[1][depth+i] && ! flag[2][n+depth-i] ) {
                        path[depth][i] = 'Q';
                        flag[0][i] = true; flag[1][depth+i] = true; flag[2][n+depth-i] = true;
                        backtrack ( n, depth+1, flag, path, res );
                        flag[0][i] = false; flag[1][depth+i] = false; flag[2][n+depth-i] = false;
                        path[depth][i] = '.';
                    }
                }
            }
        }
};