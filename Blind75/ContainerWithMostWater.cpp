//Hint
// Keep track of maxArea
// if(height[left] < height[right]) left++
// else
// right++
// Essentially try tom maximize the height
class Solution {
public:
    int maxArea(vector<int>& height) {
        int mArea = INT_MIN;
        int left = 0;
        int right = height.size() - 1;
        while(left < right)
        {
            int area = min(height[left], height[right]) * (right - left);
            if(mArea < area)
                mArea = area;
            if(height[left] < height[right]) left++;
            else
                right--;
        }
        return mArea;
    }
};