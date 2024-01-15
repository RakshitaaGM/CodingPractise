class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end)
        {
            int mid = (start + end) / 2;
            if(nums[start] <= nums[end]) return nums[start];
            if(nums[mid] > nums[end])
                start = mid + 1;
            else if(nums[start] > nums[mid])
                end = mid;
        }
        return nums[start];
    }
};