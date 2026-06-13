class Solution {
public:
    // Time Complexity: O(N) where N is the number of elements in the input array.
    // Space Complexity: O(N) where N is the number of unique elements in the input
    // array.
    // Approach: We can use a hash map to count the frequency of each element in the input array. 
    // Then, we can create a list of lists (or a vector of vectors) where the index represents the frequency and the value 
    // at that index is a list of elements with that frequency. We iterate through the hash map and populate this list of lists. 
    // Finally, we iterate through the list of lists in reverse order (from highest frequency to lowest) and collect 
    // the top K frequent elements until we have collected K elements.
    // This approach allows us to efficiently retrieve the top K frequent elements without the need for a min-heap, and it ensures that we are always collecting the most frequent elements first.
    
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Count the frequency of each element in the input array using a hash map
        unordered_map<int, int> mp;
        // Get the size of the input array
        int n = nums.size();
        // Create a list of lists (or a vector of vectors) where the index represents the frequency 
        // and the value at that index is a list of elements with that frequency
        for(int i : nums){
            mp[i]++;
        }

        // Create a list of lists (or a vector of vectors) where the index represents the frequency
        // and the value at that index is a list of elements with that frequency
        vector<vector<int>> mpList(n+1);
        // Iterate through the hash map and populate the list of lists with elements based on their frequency
        for(auto &it: mp){
            mpList[it.second].push_back(it.first);
        }

        // Iterate through the list of lists in reverse order (from highest frequency to lowest) and collect 
        // the top K frequent elements until we have collected K elements
        vector<int> result;
        // Iterate through the list of lists in reverse order (from highest frequency to lowest)
        for(int i = n; i>=0 ; i--){
            if( k == 0 ) break;
                      
            if( mpList[i].size() > 0){
                for(int j : mpList[i]){
                    result.push_back(j);
                    k--;
                }
            }
        }

        return result;
    }
};