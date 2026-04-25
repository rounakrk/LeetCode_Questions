class Solution {
public:
    // Floyd's Tortoise and Hare (Cycle Detection) Algorithm
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // The idea is to treat the numbers in the array as pointers to indices, which creates a linked list with a cycle due to the duplicate number. We use two pointers (slow and fast) to detect the cycle and find the entry point of the cycle, which is the duplicate number.
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        slow = nums[slow];
        fast = nums[nums[fast]];
        // First phase: Finding the intersection point in the cycle
        // We move the slow pointer by one step and the fast pointer by two steps until they meet. This guarantees that they will meet inside the cycle formed by the duplicate number.
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // Second phase: Finding the entrance to the cycle
        // Once they meet, we reset one pointer to the start of the array and keep the other at the meeting point. We then move both pointers one step at a time until they meet again. The point at which they meet will be the duplicate number.
        slow = nums[0];
        // We move both pointers one step at a time until they meet. The point at which they meet will be the duplicate number.
        // This works because the distance from the start to the duplicate number is equal to the distance from the meeting point to the duplicate number within the cycle.
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};