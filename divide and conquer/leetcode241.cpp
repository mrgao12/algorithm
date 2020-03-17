#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        vector< int > diffWaysToCompute ( string input ) {
            vector< int > res;
            for ( int i = 0; i < input.length(); i++ ) {
                char temp = input[i];
                if ( temp == '+' || temp == '-' || temp == '*' ) {
                    vector< int > left = diffWaysToCompute ( input.substr ( 0, i ) );
                    vector< int > right = diffWaysToCompute ( input.substr ( i+1 ) );

                    for ( int i = 0; i < left.size(); i++ ) {
                        for ( int j = 0; j < right.size(); j++ ) {
                            int l = left[i]; int r = right[j];
                            if ( temp == '+' ) res.push_back ( l + r );
                            if ( temp == '-' ) res.push_back ( l - r );
                            if ( temp == '*' ) res.push_back ( l * r );
                        }
                    }
                }
            }

            if ( res.empty() ) res.push_back ( stoi ( input ) );
            return res;
        }
};