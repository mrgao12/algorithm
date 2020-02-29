#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 52 N-Queens II
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 * problem detail:https://leetcode-cn.com/problems/n-queens-ii
 * **/

class Solution {
    public:
        int totalNQueens ( int n ) {
            vector< vector< bool > > flag ( 3, vector< bool > ( 2*n ) );
            int num = 0;

            backtrack ( n, 0, flag, num );
            return num;
        }

        void backtrack ( int n, int depth, vector< vector< bool > >& flag, int& num ) {
            if ( depth == n ) num++;
            else {
                for ( int i = 0; i < n; i++ ) {
                    if ( ! flag[0][i] && ! flag[1][depth+i] && ! flag[2][n+depth-i] ) {
                        flag[0][i] = true; flag[1][depth+i] = true; flag[2][n+depth-i] = true;
                        backtrack ( n, depth+1, flag, num );
                        flag[0][i] = false; flag[1][depth+i] = false; flag[2][n+depth-i] = false;
                    }
                }
            }
        }
};