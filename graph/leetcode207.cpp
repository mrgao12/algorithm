#include <vector>
#include <queue>
using namespace std;

class Solution {
    public:
        bool canFinish ( int numCourses, vector< vector< int > >& prerequisites ) {
            vector< vector< int > > adjacency ( numCourses );
            for ( auto edge : prerequisites ) {
                adjacency[edge[0]].push_back ( edge[1] );
            }
            int v = 0, s = v;
            vector< int >status ( numCourses, 0 );
            do {
                if ( status[v] == 0 ) {
                    if ( ! dfs ( v, adjacency, status ) ) return false;
                }
            } while ( s != ( v = ( ++v % numCourses ) ) );

            return true;
        }

        bool dfs ( int v, vector< vector< int > > const& adjacency, vector< int >& status ) {
            status[v] = 1;

            for ( auto u : adjacency[v] ) {
                if ( status[u] == 0 ) {
                    status[u] = 1;
                    if ( ! dfs ( u, adjacency, status ) ) return false;
                } else if ( status[u] == 1 ) return false;
            }
            status[v] = 2; return true;
        }
};


class Solution {
    public:
        bool canFinish ( int numCourses, vector< vector< int > >& prerequisites ) {
            vector< int > inDegree ( numCourses, 0 );
            vector< vector< int > > adjeancy ( numCourses );
            for ( auto edge : prerequisites ) {
                adjeancy[edge[0]].push_back ( edge[1] );
                inDegree[edge[1]]++;
            }

            queue< int > Q;

            for ( int i = 0; i < inDegree.size(); i++ ) {
                if ( ! inDegree[i] ) Q.push ( i );
            }

            while ( ! Q.empty() ) {
                int i = Q.top(); Q.pop(); numCourses--;
                for ( auto j : adjeancy[i] ) {
                    inDegree[j]--;
                    if ( inDegree[j] == 0 ) Q.push ( j );
                }
            }

            return !numCourses;
        }
};