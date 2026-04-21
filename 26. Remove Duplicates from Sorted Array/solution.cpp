class Solution {
public:
    // Function to remove duplicates from a sorted array in-place. The function returns the new length of the array after removing duplicates.
    // Time Complexity: O(n), where n is the size of the input array. We traverse the array once to remove duplicates and shift the remaining elements.
    // Space Complexity: O(1), as we are modifying the array in-place without using extra space for another array. We only use a constant amount of space for the index variable j to keep track of the position of the next unique element.
    // Note: The order of elements can be changed, and it doesn't matter what you leave beyond the new length of the array.
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[j]!=nums[i]){
                j+=1;
                nums[j] = nums[i];
            }
        }
        return j+1;
    }
};