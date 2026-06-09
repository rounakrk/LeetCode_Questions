class Solution {
public:
    // Dutch National Flag Algorithm
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // Approach: We maintain three pointers, i, j, and k. The pointer i keeps track of the position where the next 0 should be placed, j is the current index being evaluated, and k keeps track of the position where the next 2 should be placed. We iterate through the array with pointer j and swap elements accordingly to ensure that all 0s are moved to the beginning, all 1s are in the middle, and all 2s are moved to the end of the array.
    // This approach allows us to sort the colors in a single pass through the array, making it efficient and straightforward.
    void sortColors(vector<int>& nums) {
        int n =nums.size();

        // i: index for next 0, j: current index, k: index for next 2
        int i = 0;
        int j = 0;
        int k = n-1;

        // Iterate through the array with pointer j
        while(j <= k){
            // If the current element is 1, just move to the next element
            if(nums[j]==1) j++;
            // If the current element is 2, swap it with the element at index k and move the k pointer left
            else if(nums[j] == 2){
                swap(nums[k], nums[j]);
                k--;
            }else{ // If the current element is 0, swap it with the element at index i and move both i and j pointers right
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
    }
};