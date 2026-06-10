class Solution {
public:
    typedef pair<int, int> P;
    // Time Complexity: O(N log K) where N is the number of elements in the input array and K is the number of top frequent elements to return.
    // Space Complexity: O(N) where N is the number of unique elements in the input
    // array.
    // Approach: We can use a hash map to count the frequency of each element in the input array. Then, we can use a min-heap (priority queue) to keep track of the top K frequent elements. We iterate through the hash map and push each element and its frequency into the min-heap. If the size of the min-heap exceeds K, we pop the least frequent element. Finally, we extract the elements from the min-heap and return them as the result.
    // This approach ensures that we are always keeping the top K frequent elements in the min-heap, and it allows us to efficiently retrieve the result at the end.
    // Note: The use of a min-heap ensures that we are always keeping the least frequent element at the top, which allows us to efficiently remove it when the size exceeds K.
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int i : nums){
            mp[i]++;
        }

        priority_queue<P, vector<P>, greater<P>> pq;

        for(auto &it: mp){
            int val = it.first;
            int freq = it.second;

            pq.push({freq, val});

            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<int> result;

        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};