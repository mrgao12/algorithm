#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int majEleCandidate ( vector<int>& nums ) {
            int maj;
            for ( int c = 0, i = 0; i < nums.size(); i++ ) {
                if ( c == 0 ) {
                    maj = nums[i]; c = 1;
                } else {
                    maj == nums[i] ? c++ : c--;
                }
            }
            return maj;
        }

        bool majEleCheck ( int maj, vector<int>& nums ) {
            int c = 0;
            for ( int i = 0; i < nums.size(); i++ ) {
                if ( maj == nums[i] ) c++;
            }
            return 2 * c > nums.size();
        }

        int majorityElement ( vector<int>& nums ) {
            int maj = majEleCandidate ( nums );
            return majEleCheck ( maj, nums ) ? maj : -1;
        }
};