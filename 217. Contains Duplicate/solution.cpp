class Solution {
public:
    // Time complexity: O(n) where n is the number of elements in the input vector nums. We iterate through the vector once, and each insertion and lookup operation in the unordered_set takes O(1) on average.
    // Space complexity: O(n) in the worst case, if all elements in the input vector
    // are unique, we will store all of them in the unordered_set.
    // Overall, the algorithm efficiently checks for duplicates in the input vector using a hash set to achieve constant time lookups.
    // This approach is efficient and straightforward for solving the problem of determining if there are any duplicate elements in the input vector.
    // The use of an unordered_set allows for efficient checking of duplicates, and the algorithm runs in linear time relative to the size of the input vector.
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> arr;
        for (int num : nums){
            if(arr.contains(num)) return true;
            arr.insert(num);
        }
        return false;
    }
};