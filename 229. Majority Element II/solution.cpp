class Solution {
public:
    // Time Complexity: O(n) where n is the size of the input array nums. We traverse the array once to count the frequency of each element, and then we traverse the frequency map to find the majority elements.
    // Space Complexity: O(n) in the worst case, if all elements in the input array
    // are distinct, we will have n entries in the frequency map. However, in practice, the space complexity can be less if there are duplicate elements.
    vector<int> majorityElement(vector<int>& nums) {
        // The majority element is the element that appears more than n/3 times in the array.
        int n = nums.size();
        int minCount = floor(n/3);
        // We can use a hash map to count the frequency of each element in the array.
        unordered_map<int, int> freqMap;
        // Traverse the array and count the frequency of each element.
        for(int num : nums){
            freqMap[num]++;
        }
        // Traverse the frequency map and find the elements that appear more than n/3 times.
        vector<int> result;
        // We can use a range-based for loop to iterate through the frequency map and check if the frequency of each element is greater than minCount. If it is, we add the element to the result vector.
        for(auto const& [ele, freq] : freqMap){
            if(freq>minCount) result.push_back(ele);
        }
        return result;
    }
};