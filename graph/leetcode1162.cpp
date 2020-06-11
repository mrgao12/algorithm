#include <vector>
#include <queue>
using namespace std;

class Solution {
    public:
        int const dx[4] = { -1, 0, 1, 0 };
        int const dy[4] = { 0, -1, 0, 1 };
        vector< vector< int > > const map;
        struct Coordinate {
                int x;
                int y;
                int step;
        };

        int bfs ( int x, int y ) {
            int m = map.size();
            int n = map[0].size();

            vector< vector< bool > > visit ( m, vector<bool> ( n, false ) );
            queue<Coordinate> Q;
            Q.push ( { x, y, 0 } );

            while ( ! Q.empty() ) {
                Coordinate p = Q.front(); Q.pop();

                for ( int i = 0; i < 4; i++ ) {
                    int nx = p.x + dx[i];
                    int ny = p.y + dy[i];

                    if ( ! ( nx >= 0 && ny >= 0 && nx < m && ny < n ) ) continue;
                    if ( ! visit[nx][ny] ) {
                        visit[nx][ny] = true;
                        Q.push ( { nx, ny, p.step + 1 } );
                        if ( map[nx][ny] ) return p.step + 1;
                    }
                }
            }

            return -1;
        }
        int maxDistance ( vector< vector< int > >& grid ) {
            int md = -1;
            map = grid;
            for ( int i = 0; i < grid.size(); i++ ) {
                for ( int j = 0; j < grid[0].size(); j++ ) {
                    if ( ! grid[i][j] ) md = max ( md, bfs ( i, j ) );
                }
            }

            return md;
        }
};