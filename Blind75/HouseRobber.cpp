// Keep note of the prev, prevSec + curr. 
// Store the max of prevSec + curr and prevFirst in prevFirst
class Solution {
public:
    int rob(vector<int>& nums) {
        int prevFirst = 0, prevSecond = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = prevFirst;
            prevFirst = max(prevSecond + nums[i], prevFirst);
            prevSecond = temp;
        }
        return prevFirst;
    }
};