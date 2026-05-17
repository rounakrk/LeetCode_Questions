/* 
    Imagine you are looking at an old-school paper dictionary, and you have a list of words: 
    ["flower", "flow", "flight"].

    If you sort these words alphabetically, they become:

    - flight (The absolute first word alphabetically)
    - flow
    - flower (The absolute last word alphabetically)

    Because a dictionary is sorted alphabetically, the words that are most different from each other 
    will end up at the very beginning and the very end of the list.

    Therefore, any common prefix shared by all the words must be shared by the first word and the last word. 
    You don't need to look at flow (the middle words) at all! 
    You only need to compare flight and flower letter-by-letter until they stop matching. 
*/

class Solution {
public:

    // Time complexity: O(n log n) where n is the number of strings in the input vector strs. The sorting step takes O(n log n) time, and the subsequent comparison of the first and last strings takes O(m) time, where m is the length of the longest common prefix. However, since m is at most the length of the shortest string, we can consider it as O(1) in terms of big O notation, leading to an overall time complexity of O(n log n).
    // Space complexity: O(1) if we ignore the space used by the sorting algorithm, which typically uses O(log n) space for in-place sorting. The additional space used for storing the result string and loop variables is constant, so the overall space complexity can be considered O(1).
    // Overall, the algorithm efficiently finds the longest common prefix among a list of strings by sorting
    // the strings and comparing only the first and last strings in the sorted order. This approach minimizes the number of comparisons needed to find the longest common prefix, as it leverages the properties of sorted strings to quickly identify the common prefix shared by all strings in the list.
    // This approach is efficient and straightforward for solving the problem of finding the longest common prefix, as it relies on sorting the input strings and then comparing only the first and last strings to determine the longest common prefix, which is a common technique for this type of problem.
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        
        // We sort the input vector of strings in alphabetical order. After sorting, the first string (the smallest) and the last string (the largest) will be the most different from each other. Therefore, any common prefix shared by all the strings must be shared by these two strings. We can then compare the first and last strings character by character until we find a mismatch or reach the end of either string, which will give us the longest common prefix.
        sort(strs.begin(), strs.end());
        string first = strs.front();
        string last = strs.back();
        string result = "";

        // We compare the first and last strings character by character until we find a mismatch or reach the end of either string. If a mismatch is found or if we reach the end of either string, we return the result accumulated so far, which represents the longest common prefix found up to that point. If all characters match, we continue until we have compared all characters of the shorter string, and then we return the result as the longest common prefix.
        for(int i = 0 ; i < first.length() ; i++){
            // We compare the first and last strings character by character until we find a mismatch or reach the end of either string. If a mismatch is found or if we reach the end of either string, we return the result accumulated so far, which represents the longest common prefix found up to that point. If all characters match, we continue until we have compared all characters of the shorter string, and then we return the result as the longest common prefix.
            if(i >= last.length() || first[i] != last[i]) return result;
            result += first[i];
        }

        // If all characters match, we continue until we have compared all characters of the shorter string, and then we return the result as the longest common prefix.
        return result;
    }
};