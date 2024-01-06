// Given an integer n, return an array ans of length n + 1 such that 
// for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
class Solution {
public:
vector<int> countBits(int n) {
    vector<int> ans;
    for(int i = 0; i <= n; i++)
    {
       int c = 0;
       int n = i;
       while(n != 0)
       {
           if(n%2 != 0) c++;
            n = n/2;
       }
       ans.emplace_back(c); 
    }
       return ans; 
    }
};