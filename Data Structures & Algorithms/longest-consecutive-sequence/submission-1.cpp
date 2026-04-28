class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxCount = 0;
        int count=0;
        sort(nums.begin() , nums.end());
        if(nums.empty())return 0;
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]+1==nums[i+1])
            {
                count++;
            }
            else if(nums[i]==nums[i+1])
            {}
            else {
                count=0;
            }
            maxCount = max(maxCount , count);
        }
        return maxCount+1;
    }
};
