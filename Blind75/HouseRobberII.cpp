//Hint : You can either pick first element or last element. You cannot pick array with both
// Do the same as Rob problem with first element included and another time with last element
// included. Return the max of both
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int prevFirst = 0;
        int prevSecond = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            auto temp = prevFirst;
            prevFirst = max(prevSecond + nums[i], prevFirst);
            prevSecond = temp;
        }
        auto max1 = prevFirst;
        prevFirst = 0;
        prevSecond = 0;
        for(int i = 1; i <= nums.size() - 1; i++)
        {
            auto temp = prevFirst;
            prevFirst = max(prevSecond + nums[i], prevFirst);
            prevSecond = temp;
        }
        return max(max1, prevFirst);
        
    }
};