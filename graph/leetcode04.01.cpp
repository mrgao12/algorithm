#include <vector>
#include <queue>
using namespace std;

class Solution {
    public:
        void dfs ( bool& flag, vector< bool >& status, int start, int target, vector< vector< int > >& adjancey ) {
            status[start] = 1;
            for ( auto u : adjancey[start] ) {
                if ( u == target ) { flag = true; return; }
                if ( status[u] == 0 ) dfs ( flag, status, u, target, adjancey );
            }
        }

        bool findWhetherExistsPath( int n, vector< vector< int > >& graph, int start, int target ) {
            bool flag = false;
            vector< vector< int > > adjancey ( n );
            vector< bool > status ( n, 0 );

            for ( auto edge : graph ) {
                adjancey[edge[0]].push_back ( edge[1] );
            }

            dfs ( flag, status, start, target, adjancey );
            return flag;
        }
};

class Solution {
    public:
        void bfs ( bool& flag, vector< bool >& status, int start, int target, vector< vector< int > >& adjancey ) {
            queue< int > Q; Q.push ( start );

            while ( ! Q.empty() ) {
                int v = Q.front(); Q.pop(); status[v] = 1;
                for ( auto u : adjancey[v] ) {
                    if ( u == target ) { flag = true; return; }
                    if ( status[u] == 0 ) Q.push ( u );
                }
            }
        }
        
        bool findWhetherExistsPath( int n, vector< vector< int > >& graph, int start, int target ) {
            bool flag = false;
            vector< vector< int > > adjancey ( n );
            vector< bool > status ( n, 0 );

            for ( auto edge : graph ) {
                adjancey[edge[0]].push_back ( edge[1] );
            }

            bfs ( flag, status, start, target, adjancey );
            return flag;
        }
};