class Solution {
    public:
        bool dfs ( vector< vector< int > > const& graph, int u, vector<int>& status ) {
            if ( status[u] > 0 ) return status[u] == 2;
            
            status[u] = 1;
            for ( auto v : graph[u] ) {
                if ( status[v] == 2 ) continue;
                if ( status[v] == 1 || dfs ( graph, v, status ) ) return false;
            }
            status[u] = 2; return true;
        }
        vector<int> eventualSafeNodes ( vector< vector< int > >& graph ) {
            vector<int> res;
            int n = graph.size();

            for ( int i = 0; i < n; i++ ) {
                vector<int> status ( n, 0 );
                if ( dfs ( graph, i, status ) ) res.push_back ( i );
            }

            return res;
        }
};