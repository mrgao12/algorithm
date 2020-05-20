#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        int smallestDivisor ( vector<int>& nums, int threshold ) {
            int lo = 1, hi = 0;
            for ( int num : nums ) hi = max ( num, hi );
            hi++;

            while ( 2 < hi - lo ) {
                int mi = ( lo + hi ) >> 1;

                if ( isOK ( nums, mi, threshold ) ) {
                    hi = mi;
                } else lo = mi;
            }
        }
};