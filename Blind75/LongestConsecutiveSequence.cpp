// Hint:
// Take a number from the vector, track next and prev and check whether they are there in the map
// Set them to false if found to avoid duplication
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> m;
        for(int n : nums)
            m[n] = true;
        int res = 0;
        for(int n : nums)
        {
            if(m[n])
            {
                int next = n + 1;
                int prev = n - 1;
                while(m[next])
                {
                    m[next] = false;
                    next = next + 1;
                }
                while(m[prev])
                {
                    m[prev] = false;
                    prev = prev - 1;
                }
                m[n] = false;
                if((next - prev - 1) > res)
                    res = next - prev - 1;
            }
        }
        return res;
    }
};