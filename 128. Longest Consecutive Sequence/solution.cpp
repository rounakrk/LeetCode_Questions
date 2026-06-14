class Solution {
public:
    // 1. Convert to unordered_set to get instant O(1) search speeds.
    // 2. Only start counting if (num - 1) doesn't exist, meaning 'num' is the true start of a sequence.

    // The longestConsecutive function finds the length of the longest consecutive sequence in an unsorted array of integers. It first converts the input vector nums into an unordered set st for O(1) average time complexity lookups. The function then iterates through each number in the set. For each number, it checks if the previous number (num - 1) is not present in the set, indicating that the current number is the start of a new sequence. If it is the start, it initializes a counter len to 1 and continues to check for consecutive numbers (current + 1) in the set, incrementing len for each found consecutive number. Finally, it updates the longest variable with the maximum length found and returns it after checking all numbers.

    int longestConsecutive(vector<int>& nums) {
        // Convert the input vector nums into an unordered set st for O(1) average time complexity lookups. This allows for efficient checking of the presence of consecutive numbers in the sequence.
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        // Iterate through each number in the unordered set st. For each number, check if the previous number (num - 1) is not present in the set. If it is not present, it indicates that the current number is the start of a new consecutive sequence. Initialize a counter len to 1 and continue to check for consecutive numbers (current + 1) in the set, incrementing len for each found consecutive number. Update the longest variable with the maximum length found after checking all numbers.
        for (int i : st){

            // Check if the previous number (i - 1) is not present in the unordered set st. If it is not present, it indicates that the current number i is the start of a new consecutive sequence. This check ensures that we only start counting from the beginning of a sequence, avoiding redundant counts for numbers that are part of an already counted sequence.
            if(st.find(i-1) == st.end()){
                int current = i;
                int len = 1;

                while(st.find(current+1) != st.end()){
                    current += 1;
                    len += 1;
                }

                longest = max(len, longest);
            }
        }

        return longest;
    }
};