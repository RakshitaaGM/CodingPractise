// Keep track of min and max  product of current subarray
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = *max_element(nums.begin(), nums.end());
        int currMax = 1;
        int currMin = 1;
        for(auto n : nums)
        {
            if(n == 0)
            {
                currMax = 1;
                currMin = 1;
                continue;
            }
            auto temp = n * currMax;
            currMax = max(n * currMax, max(n * currMin, n));
            currMin = min(temp, min(n * currMin, n));
            res = max(res, currMax);
        }
        return res;
    }
};