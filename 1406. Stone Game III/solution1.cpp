class Solution {
public:
    vector<int> t;
    long long n;

    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // The function `stoneGameIII` determines the winner of the stone game given the values of stones. It uses a recursive helper function `solve` with memoization to calculate the maximum score difference Alice can achieve over Bob starting from index `i`. The result is compared to determine if Alice wins, Bob wins, or if it's a tie.
    int solve(vector<int>& stones, int i){
        if(i>=n) return 0;

        if(t[i] != -1) return t[i];

        // Alice can take 1, 2, or 3 stones, and we calculate the score difference accordingly.
        int result =stones[i] - solve(stones, i+1);

        // If Alice takes 2 stones, we check if the next index is within bounds and calculate the score difference.
        if(i+1<n)
            result = max(result, stones[i] + stones[i+1] - solve(stones, i+2));

        // If Alice takes 3 stones, we check if the next index is within bounds and calculate the score difference.
        if(i+2<n)
            result = max(result, stones[i] + stones[i+1] + stones[i+2] - solve(stones, i+3));
        
        // Store the result in the memoization table and return it.
        return t[i] = result;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        t.resize(n+1, -1);

        int result = solve(stoneValue, 0);

        if(result>0) return "Alice";
        if(result<0) return "Bob";

        return "Tie";
    }
};