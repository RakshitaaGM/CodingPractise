// Hint:
// Construct a 2D bool vector
class Solution {
public:
    bool same(vector<vector<bool>>& dp, string& str, int s, int e)
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
        if(str[s] == str[e] && dp[s + 1][e - 1])
            return dp[s][e] = true;
        return dp[s][e] = false;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int startIdx = 0;
        for(int g = 0; g < n; g++)
        {
            for(int start = 0, end = g; end < n; start++, end++)
            {
                same(dp, s, start, end);
                if(dp[start][end])
                {
                    if(end - start + 1 > maxLen)
                    {
                        maxLen = end - start + 1;
                        startIdx = start;
                    }
                }
            }
        }
        return s.substr(startIdx, maxLen);        
    }
};