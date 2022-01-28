#include<bits/stdc++.h>
using namespace std;


// mine approach
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        int j = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] != nums[i + 1])
            {
                nums[j++] = nums[i];
            }
        }
        if (j == 0)
            return 1;
        else if (nums[j - 1] == nums[nums.size() - 1])
            return j;
        nums[j] = nums[nums.size() - 1];
        j++;
        return j;
    }
};

// other old approach
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        int pre = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != nums[pre])
            {
                nums[++pre] = nums[i];
            }
        }
        if (nums.size() > 0)
        {
            return pre + 1;
        }
        else
        {
            return pre;
        }
    }
};
