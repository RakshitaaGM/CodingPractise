//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
// Note: 
// Use priority queue to order elements according to frequency
// priority queue uses first element if it is pair
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto n : m)
        {
            pq.emplace(n.second, n.first);
        }
        int i = 1;
        vector<int> res;
        while(i <= k  && !pq.empty()){
            
            res.emplace_back(pq.top().second);
            pq.pop();
            i++;
        }
        return res;
    }
};