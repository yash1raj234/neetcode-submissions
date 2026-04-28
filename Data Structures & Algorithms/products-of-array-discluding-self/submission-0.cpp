class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int product=1; int zeroCount=0;
    for(auto it :nums)
    {
        if(it!=0)
        {
        product = it*product;
        }
        else 
        {
            zeroCount++;
        }
    }
    vector<int> res(nums.size() , 0);
    if(zeroCount>1)
    {
     return res;
    }
    for(int i = 0; i<nums.size() ; i++)
    {   
       if (zeroCount > 0) {
                res[i] = (nums[i] == 0) ? product : 0;
            } else {
                res[i] = product / nums[i];
            }
    }
    return res;
    }
};
