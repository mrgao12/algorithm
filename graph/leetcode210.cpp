#include <vector>
using namespace std;

class Solution {
    public:
        bool tSort ( int v, vector< vector< int > > const& adjancey, vector<int>& status, vector<int>& res ) {
            status[v] = 1;
            for ( auto u : adjancey[v] ) {
                if ( status[u] == 0 ) {
                    if ( ! tSort ( u, adjancey, status, res ) ) {
                        return false;
                    }
                } else if ( status[u] == 1 ) return false;
            }
            status[v] = 2; res.push_back ( v ); return true;
        }
        vector<int> findOrder ( int numCourses, vector< vector< int > >& prerequisites ) {
            vector<int> res;
            vector<int> status ( numCourses, 0 );
            vector< vector< int > > adjancey ( numCourses );

            for ( auto edge : prerequisites ) {
                adjancey[edge[0]].push_back ( edge[1] );
            }

            int v = 0; int s = v;

            do {
                if ( status[v] == 0 ) {
                    if ( ! tSort ( v, adjancey, status, res ) ) {
                        res.clear();
                        return res;
                    }
                }
            } while ( s != ( v = ( ++v % numCourses ) ) );

            return res;
        }
};