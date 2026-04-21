class Solution {
public:
    // Function to remove all occurrences of val in nums in-place. The function returns the new length of the array after removing the specified value.
    // Time Complexity: O(n), where n is the size of the input array. We traverse the array once to remove the specified value and shift the remaining elements.
    // Space Complexity: O(1), as we are modifying the array in-place without using extra space for another array. We only use a constant amount of space for the index variable j to keep track of the position of the next non-val element.
    // Note: The order of elements can be changed, and it doesn't matter what you leave beyond the new length of the array.
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for(int i=0;i<nums.size(); i++){
            if(nums[i]!=val){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};