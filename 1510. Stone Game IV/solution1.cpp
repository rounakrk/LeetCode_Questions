class Solution {
public:
    vector<int> t;

    // Recursive function to determine if the current player can win
    // The function checks if the current player can force a win given the remaining number of stones `n`. It uses memoization to store previously computed results in the vector `t`, where `t[i]` indicates whether the player can win with `i` stones left.
    // Time Complexity: O(n * sqrt(n)), where n is the number of stones. The outer loop runs for each value of n, and the inner loop runs for each perfect square less than or equal to n.
    // Space Complexity: O(n), for the memoization array `t`.
    bool solve(int n){
        if(n == 0) return false; 
        
        if(t[n] != -1) return t[n] == 1; 
        
        for(int i = 1 ; i * i <= n ; i++){ 
            if(solve(n - i * i) == false) {
                t[n] = 1;
                return true;
            }
        } 
        
        t[n] = 0;
        return false; 
    }

    bool winnerSquareGame(int n) {
        t.assign(n+1, -1);
        return solve(n);
    }
};