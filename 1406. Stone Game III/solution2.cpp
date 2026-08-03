class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        // Time Complexity: O(n)
        // Space Complexity: O(n)
        int n = stoneValue.size();
        vector<int> t(n+1); // t[i] represents the maximum score difference Alice can achieve over Bob starting from index i

        // We iterate from the end of the stoneValue array to the beginning, calculating the maximum score difference for each index.
        for(int i = n-1; i>=0 ; i--){
            // If Alice takes 1 stone, we calculate the score difference and store it in t[i].
            t[i] = stoneValue[i] - t[i+1];

            // If Alice takes 2 stones, we check if the next index is within bounds and calculate the score difference.
            if(i+2 <= n)
                t[i] = max(t[i], stoneValue[i] + stoneValue[i+1] - t[i+2]);

            // If Alice takes 3 stones, we check if the next index is within bounds and calculate the score difference.
            if(i+3 <= n)
                t[i] = max(t[i], stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - t[i+3]);
        }
        
        int result = t[0];

        if(result>0) return "Alice";
        if(result<0) return "Bob";

        return "Tie";
    }
};