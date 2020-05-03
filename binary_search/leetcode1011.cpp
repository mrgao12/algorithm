#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool isOK ( vector<int>& weights, int container, int D ) {
            int sum = 0, i = 0;
            while ( i < weights.size() ) {
                if ( sum + weights[i] <= container ) {
                    sum += weights[i++];
                } else {
                    D--;
                    sum = 0;
                }
            }

            return D > 0;
        }

        int shipWithinDays ( vector<int>& weights, int D ) {
            int max = 0, sum = 0;
            for ( int i = 0; i < weights.size(); i++ ) {
                sum += weights[i];
                if ( weights[i] > max ) max = weights[i];
            }
            int lo = max, hi = sum + 1;

            while ( lo < hi ) {
                int mi = ( lo + hi ) >> 1;
                if ( isOK ( weights, mi, D ) ) hi = mi;
                else lo = mi + 1; 
            }

            return lo;
        }
};


int main() {
    int a[] = { 1,2,3,4,5,6,7,8,9,10 };
    Solution s;
    vector<int> weights ( a, a+10 );
    cout << s.shipWithinDays ( weights, 5 ) << endl;
    system("pause");
    return 0;
}