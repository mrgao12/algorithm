#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 152 Maximum Product Subarray
 * Given an integer array nums, 
 * find the contiguous subarray within an array (containing at least one number) which has the largest product.
 * problem detail:https://leetcode-cn.com/problems/maximum-product-subarray
 * **/

class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int n = nums.size(), maxPro = nums[0];
            vector< int > dp_max ( n ); vector< int > dp_min ( n );
            dp_max[0] = nums[0]; dp_min[0] = nums[0];
            for ( int i = 1; i < n; i++ ) {
                if ( nums[i] > 0 ) {
                    dp_max[i] = max ( dp_max[i-1] * nums[i], nums[i] );
                    dp_min[i] = min ( dp_min[i-1] * nums[i], nums[i] );
                } else {
                    dp_max[i] = max ( dp_min[i-1] * nums[i], nums[i] );
                    dp_min[i] = min ( dp_max[i-1] * nums[i], nums[i] );
                }

                if ( dp_max[i] > maxPro ) maxPro = dp_max[i];
            }
            return maxPro;
        }
};