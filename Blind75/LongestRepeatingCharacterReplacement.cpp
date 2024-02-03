// We can solve this problem using Four approaches. (Here I have explained all the possible solutions of this problem).

// Solved using Array(Three Nested Loop). Brute Force Approach.
// Solved using Array + Sorting. Brute Better Approach.
// Solved using Array + Hash Table(Unordered map). Optimize Approach.
// Solved using Array + Hash Table (Unordered set). Optimize Approach.
class Solution {
public:
    int characterReplacement(string s, int k) {
     unordered_map<char, int> m;
    int left = 0;
    int res = 0;
    for(int right = 0; right < s.length(); right++)
    {
        m[s[right]]++;
        if(((right-left+1) - max_element(m.begin(), m.end(), [](const auto& a, const auto b){
            return a.second < b.second;
        })->second) <= k)
        {
            res = max(res, right-left+1);
        }
        else
        {
            m[s[left]]--;
            left++;
        }
    }
    return res;  
    }
};