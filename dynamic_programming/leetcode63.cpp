#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 53 Maximum Subarray
 * Given an integer array nums, find the contiguous subarray 
 * (containing at least one number) which has the largest sum and return its sum.
 * problem detail:https://leetcode-cn.com/problems/maximum-subarray
 * **/

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size(), maxsum = nums[0];
            vector< int >dp ( n );
            dp[0] = nums[0];

            for ( int i = 1; i < n; i++ ) {
                dp[i] = max ( nums[i], dp[i-1] + nums[i] );

                if ( dp[i] > maxsum ) maxsum = dp[i];
            }

            return maxsum;
        }
};

int main()
{
    Solution res;
    int a[] = { -2,1,-3,4,-1,2,1,-5,4 };
    vector<int> nums ( a, a+9 );
    cout << res.maxSubArray(nums) << endl;
    system("pause");
    return 0;
}