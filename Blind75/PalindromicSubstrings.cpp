// Hint : Same as Longest Palindromic substrings
class Solution {
public:
    bool same(vector<vector<bool>>& dp, string str, int s, int e)
    {
        if(s == e)
            return dp[s][e] = true;
        if(e - s == 1)
        {
            if(str[s] == str[e])
                return dp[s][e] = true;
            else
                return dp[s][e] = false;
        }
        if(str[s] == str[e] && dp[s+1][e-1])
            return dp[s][e] = true;
        return dp[s][e] = false;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int c = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int g = 0; g < n; g++)
        {
            for(int start = 0, end = g; end < n; start++, end++)
            {
                same(dp, s, start, end);
                if(dp[start][end])
                {
                    c++;
                }
            }
        }
    return c; 
    }
};