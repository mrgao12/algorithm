#include <iostream>
#include <vector>
using namespace std;

/**
 * leetcode 300 Longest Increasing Subsequence
 * Given an unsorted array of integers, 
 * find the length of longest increasing subsequence.
 * problem detail:https://leetcode-cn.com/problems/longest-increasing-subsequence
 * **/

class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size(), maxLen = 0;
            vector<int>dp ( n, 1 );

            for ( int i = 1; i < n; i++ ) {
                for ( int j = 0; j < i; j++ ) {
                    if ( nums[i] > nums[j] ) dp[i] = max ( dp[i], dp[j] + 1 );
                    if ( dp[i] > maxLen ) maxLen = dp[i];
                }
            }

            return maxLen;
        }
};

int main()
{
    Solution res;
    int a[] = { 10,9,2,5,3,7,101,18 };
    vector<int> nums ( a, a+8 );
    cout << res.lengthOfLIS(nums) << endl;
    system("pause");
    return 0;
}