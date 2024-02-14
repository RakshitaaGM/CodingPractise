class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(uint i = 1; i < dp.size(); i++)
        {
            for(auto c : coins)
            {
                int diff = i - c;
                if(diff >=0)
                {
                    dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
        }
        if(dp[amount] == amount + 1)
            return -1;
        return dp[amount];
    }
};