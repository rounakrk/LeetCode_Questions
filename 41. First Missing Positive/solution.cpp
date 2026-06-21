class Solution {
public:

    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // Explanation: We use an unordered set to store all the positive integers from the input vector
    // We also keep track of the minimum and maximum positive integers encountered.
    // We first check if the number 1 is present in the set, if not we return 1 as the smallest missing positive integer.
    // If the minimum positive integer is greater than 1, we return min_val - 1 as the smallest missing positive integer.
    // We then iterate from the minimum positive integer to the maximum positive integer, checking if each integer is present in the set.
    // If we find an integer that is not present in the set, we return that integer as the smallest missing positive integer.
    // If we finish the loop without finding any missing integer, we return max_val + 1 as the smallest missing positive integer.
    // This approach ensures that we efficiently find the smallest missing positive integer in O(n) time, and the space complexity is O(n) due to the use of the unordered set to store the positive integers.
    // Overall, this solution is effective for solving the problem of finding the first missing positive integer in an unsorted array.
    // This method is straightforward and easy to understand, making it a good choice for this problem. It efficiently handles edge cases such as when the input vector contains only negative numbers or when the smallest positive integer is greater than 1.
    // This solution is optimal for this problem as it directly checks for the presence of integers in the set without the need for sorting or additional data structures, making it efficient and easy to implement.
    // Overall, this method provides a clear and concise way to find the first missing positive integer in an unsorted array, making it a suitable solution for this problem.
    // This solution is efficient and straightforward, making it easy to understand and implement. It effectively handles edge cases and provides a clear approach to finding the first missing positive integer in an unsorted array.
    // Overall, this method is a good choice for solving the problem of finding the first missing positive integer in an unsorted array, as it efficiently checks for the presence of integers and handles edge cases effectively.

    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        int min_val = INT_MAX;
        int max_val = 1;
        for(int i : nums){
            if(i>0){
                s.insert(i);
                min_val = min(min_val, i);
                max_val = max(max_val, i);
            }
        }
        int i;
        if(!s.contains(1)) return 1;
        if(min_val-1 > 0) return min_val - 1;
        
        for(i = min_val ; i < max_val ; i++){
            if(s.contains(i)) continue;
            else{
                return i;
            }
        }
        
        return i+1;
    }
};