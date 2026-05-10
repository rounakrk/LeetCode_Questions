class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(n)
    // Approach: We create a new vector of size 2*n and fill it with the elements of the original vector twice.
    // We iterate through the original vector and fill the first n elements of the result vector with the original elements and the next n elements with the same original elements.
    // Finally, we return the result vector.
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(2*n);
        for (int i = 0; i<n ; i++){
            result[i] = nums[i];
            result[i+n] = nums[i];
        }
        return result;
    }
};