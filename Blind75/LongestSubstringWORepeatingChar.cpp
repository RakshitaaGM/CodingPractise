// Hint
//Use map to keep track of the frequency and start and end for window
// If map size < window size, then there is repeating chars
// reduce the frequency and window size (start++) until map size == window size
// Delete the entry if it's frequence is 0
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        unordered_map<char, int> m;
        int i = 0;
        int j = 0;
        int res = INT_MIN;
        while(j < s.length())
        {
            m[s[j]]++;
            if(m.size() == j-i+1)
            {
                res = max(res, j-i+1);
            }
            else if(m.size() < j-i+1)
            {
                while(m.size() < j-i+1)
                {
                    m[s[i]]--;
                    if(m[s[i]] == 0)
                    {
                        m.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return res;
        
    }
};