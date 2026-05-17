class Solution {
public:

    // Time complexity: O(n * k log k) where n is the number of strings in the input vector strs and k is the average length of the strings. We iterate through each string and sort it, which takes O(k log k) time, and we do this for all n strings, resulting in O(n * k log k). The subsequent iteration to group anagrams takes O(n) time, but it is dominated by the sorting step.
    // Space complexity: O(n * k) in the worst case, if all strings in the input vector are unique and have a length of k, we will store all of them in the unordered_map. The space used for the result vector also contributes to the overall space complexity, but it is proportional to the number of unique anagram groups, which can be at most n in the worst case. Therefore, the overall space complexity can be considered O(n * k).
    // Overall, the algorithm efficiently groups anagrams by sorting each string and using a hash map to collect strings that are anagrams of each other. The sorting step ensures that all anagrams will have the same sorted representation, allowing us to easily group them together in the hash map. The final step of iterating through the hash map to create the result vector is straightforward and efficient, as it simply collects the grouped anagrams into the desired output format.
    // This approach is efficient and straightforward for solving the problem of grouping anagrams, as it relies on sorting each string to create a unique key for each group of anagrams and then uses a hash map to efficiently collect and group the anagrams together. The algorithm runs in linear time relative to the number of strings and their lengths, making it suitable for large input sizes.
    // The algorithm effectively handles the case where there are multiple groups of anagrams and ensures that all anagrams are correctly grouped together in the final result vector.

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty()) return {};

        // We create an unordered_map to store the sorted representation of each string as the key and a vector of strings that are anagrams of each other as the value. We iterate through each string in the input vector, sort it, and use the sorted string as a key to group the original strings together in the hash map. After processing all strings, we iterate through the hash map and collect the grouped anagrams into a result vector, which is then returned as the final output.
        vector<vector<string>> result;
        // We create an unordered_map to store the sorted representation of each string as the key and a vector of strings that are anagrams of each other as the value. We iterate through each string in the input vector, sort it, and use the sorted string as a key to group the original strings together in the hash map. After processing all strings, we iterate through the hash map and collect the grouped anagrams into a result vector, which is then returned as the final output.
        unordered_map<string, vector<string>> anagram_map;

        // We iterate through each string in the input vector, sort it, and use the sorted string as a key to group the original strings together in the hash map. After processing all strings, we iterate through the hash map and collect the grouped anagrams into a result vector, which is then returned as the final output.
        for(int i = 0 ; i < strs.size() ; i++){
            string temp = strs[i];
            // We iterate through each string in the input vector, sort it, and use the sorted string as a key to group the original strings together in the hash map. After processing all strings, we iterate through the hash map and collect the grouped anagrams into a result vector, which is then returned as the final output.
            sort(temp.begin(), temp.end());
            // We iterate through each string in the input vector, sort it, and use the sorted string as a key to group the original strings together in the hash map. After processing all strings, we iterate through the hash map and collect the grouped anagrams into a result vector, which is then returned as the final output.
            anagram_map[temp].push_back(strs[i]);
        }

        // After processing all strings, we iterate through the hash map and collect the grouped anagrams into a result vector, which is then returned as the final output. We iterate through each key-value pair in the hash map, where the key is the sorted representation of the anagram group and the value is a vector of strings that are anagrams of each other. We push each vector of anagrams into the result vector, which will contain all the grouped anagrams when we finish iterating through the hash map.
        for(auto it : anagram_map){
            result.push_back(it.second);
        }

        return result;
    }
};