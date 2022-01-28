#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ans = 0, len = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                len++;
            }
            else
            {
                ans = max(ans, len);
                len = 0;
            }
            if (i == nums.size() - 1)
                ans = max(ans, len);
        }
        return ans;
    }
};