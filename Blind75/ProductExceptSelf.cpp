// hint
// find left product first
// keep track of right product .
// current element equal to left * right
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n = nums.size();
      vector<int> res(n);
      res[0] = nums[0];
      for(int i = 1; i < n; i++){
          res[i] = res[i - 1] * nums[i];
      }
      int product = 1;
      for(int i = n - 1; i >= 0; i--)
      {
          if(i == n - 1) 
            res[i] = res[i-1];
          else if(i == 0)
            res[i] = product;
          else
            res[i] = res[i-1] * product;
          product = product * nums[i];
      }
      return res;
    }
};