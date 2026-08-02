class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // The function `stoneGame` determines if Alice can win the stone game given the piles of stones. It calculates the total score for even and odd indexed piles, and then compares Alice's maximum possible score with half of the total sum of stones to determine if she wins.
    bool stoneGame(vector<int>& piles) {
        int e = 0;
        int o = 0;
        int n = piles.size();
        int s = 0;
        for(int i=0; i<n ; i+=2){
            e += piles[i];
            o += piles[i+1];
            s += piles[i] + piles[i+1];
        }
        int alice_score = max(e, o);

        return alice_score > s/2;
    }
};