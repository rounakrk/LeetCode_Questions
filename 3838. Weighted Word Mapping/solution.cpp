class Solution {
public:

    // Time Complexity: O(n)
    // Space Complexity: O(n)

    int wordIndex(string s, vector<int>& weights){
        int result = 0;
        for(char i : s){
            result += weights[(int)i - 97];
        }
        return result%26;
    }

    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // Approach: We can iterate through the words and calculate the weight of each word using the wordIndex function. 
    // Then, we can map the weight to a character by subtracting the weight from 122 (the ASCII value of 'z') and converting 
    // it to a character. Finally, we can concatenate the characters to form the result string.

    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        for(string s : words){
            int wI = wordIndex(s, weights);
            string a{(char)(122-wI)};
            result += a;
        }
        return result;
    }
};