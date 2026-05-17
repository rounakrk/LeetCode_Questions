class Solution {
public:
    // Time complexity: O(m*n) where m is the number of strings in the input vector strs and n is the length of the longest common prefix. In the worst case, we compare each character of the longest common prefix with each string in the vector, resulting in a time complexity proportional to the product of m and n.
    // Space complexity: O(1) since we are using a constant amount of extra space to store the result string and the loop variables. The space used does not grow with the input size, making it constant.
    // Overall, the algorithm efficiently finds the longest common prefix among a list of strings by iterating
    // through the characters of the first string and comparing them with the corresponding characters of the other strings. The algorithm terminates as soon as a mismatch is found or when we reach the end of any string, ensuring that we only compare characters that are part of the common prefix.
    // This approach is efficient and straightforward for solving the problem of finding the longest common prefix, as
    
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        
        // We iterate through the characters of the first string and compare them with the corresponding characters of the other strings. The algorithm terminates as soon as a mismatch is found or when we reach the end of any string, ensuring that we only compare characters that are part of the common prefix.
        for(int i = 0 ; i < strs[0].length() ; i++){
            
            // We iterate through the characters of the first string and compare them with the corresponding characters of the other strings. The algorithm terminates as soon as a mismatch is found or when we reach the end of any string, ensuring that we only compare characters that are part of the common prefix. If a mismatch is found or if we reach the end of any string, we return the result accumulated so far, which represents the longest common prefix found up to that point.
            for(string s : strs){
                
                // We iterate through the characters of the first string and compare them with the corresponding characters of the other strings. The algorithm terminates as soon as a mismatch is found or when we reach the end of any string, ensuring that we only compare characters that are part of the common prefix. If a mismatch is found or if we reach the end of any string, we return the result accumulated so far, which represents the longest common prefix found up to that point.
                if(i >= s.length() || s[i] != strs[0][i]) return result;
            }
            
            result += strs[0][i];
        }
        
        return result;
    }
};