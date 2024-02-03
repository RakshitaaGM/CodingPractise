// have two variables for to track required length nad what you have. 
// if have == need , then reduce the size of th ewindow from left and reduce have
class Solution {
public:
    string minWindow(string s, string t) {
        if(t == " ") return "";
        unordered_map<char, int> T;
        unordered_map<char, int> window;
        int minLen = INT_MAX;
        for(auto c : t)
        {
            T[c]++;
        }
        int have = 0;
        int need = T.size();
        int l = -1;
        int left = 0;
        for(int right = 0; right < s.length(); right++)
        {
            window[s[right]]++;
            if(T[s[right]] > 0 && window[s[right]] == T[s[right]])
                have++;
            
            while(have == need)
            {
                // Find minlength
                if(minLen > (right - left + 1))
                {
                    minLen = right - left + 1;
                    l = left;
                }
                window[s[left]]--;
                if(T[s[left]] > 0 && window[s[left]] < T[s[left]])
                {
                    have--;
                }
                left = left + 1;
            }
        }
        if(minLen == INT_MAX)
            return "";
        return s.substr(l, minLen);
        
    }
};