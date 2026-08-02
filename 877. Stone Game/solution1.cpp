class Solution {
public:
    // Time Complexity: O(n^2)
    // Space Complexity: O(n^2)

    int t[501][501];

    // The function `solve` is a recursive function that calculates the maximum score Alice can achieve from the piles of stones. It uses memoization to store previously computed results in the 2D array `t` to avoid redundant calculations.
    int solve(vector<int>& piles,int i, int j){
        if(i>j) return 0;
        
        if(t[i][j]!=-1) return t[i][j];

        int take_i = piles[i] + min(solve(piles, i+2, j), solve(piles, i+1, j-1));
        int take_j = piles[j] + min(solve(piles, i, j-2), solve(piles, i+1, j-1));
        
        return t[i][j] = max(take_i, take_j);
    }
    bool stoneGame(vector<int>& piles) {
        // The function `stoneGame` determines if Alice can win the stone game given the piles of stones. It initializes the memoization table, calculates the total sum of stones, and calls the `solve` function to get Alice's maximum score. Finally, it checks if Alice's score is greater than half of the total sum to determine if she wins.
        int n = piles.size();
        // Initialize the memoization table `t` with -1 to indicate that no subproblems have been solved yet.
        memset(t, -1, sizeof(t));
        // Calculate the total sum of stones in all piles using the `accumulate` function from the `<numeric>` header.
        int s = accumulate(begin(piles), end(piles), 0);

        int alice_score = solve(piles, 0, n-1);
        // Check if Alice's score is greater than half of the total sum of stones. If it is, Alice wins the game, and the function returns true; otherwise, it returns false.
        return alice_score > s/2;
    }
};