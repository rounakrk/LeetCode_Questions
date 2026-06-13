class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(1) (excluding the output array)
    // Approach: We can use two passes to calculate the product of all elements except self. In the first pass, we calculate the product of all elements to the left of each index and store it in the result array. In the second pass, we calculate the product of all elements to the right of each index and multiply it with the corresponding value in the result array.
    // This approach allows us to achieve the desired result without using extra space for left and right product arrays, thus optimizing space complexity to O(1).
    vector<int> productExceptSelf(vector<int>& nums) {
        // Initialize the result array with 1s
        int n = nums.size();
        vector<int> result(n, 1);

        // First pass: Calculate the product of all elements to the left of each index
        for(int i = 1; i<n ; i++){
            result[i] = result[i-1] * nums[i-1];
        }
        // Second pass: Calculate the product of all elements to the right of each index and multiply it with the corresponding value in the result array
        int x = 1;
        for(int i = n-2 ; i>=0 ; i--){
            // Update x to be the product of all elements to the right of the current index
            x *= nums[i+1];
            // Multiply the current value in the result array with x to get the final product except self for the current index
            result[i] = result[i] * x;
        }

        return result;
    }
};