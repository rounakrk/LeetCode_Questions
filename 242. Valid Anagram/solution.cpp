class Solution {
public:
    // Time complexity: O(n) where n is the length of the input strings s and t. We iterate through both strings once to count the frequency of each character, and then we iterate through the frequency vector once to check if all counts are zero.
    // Space complexity: O(1) since the size of the frequency vector is fixed at 26 (for lowercase English letters), regardless of the input size. The space used does not grow with the input size, making it constant.
    // Overall, the algorithm efficiently checks if two strings are anagrams by counting the frequency of each character and ensuring that the counts match for both strings. The use of a fixed-size frequency vector allows for constant space usage, and the linear time complexity makes it suitable for large input strings.
    // This approach is efficient and straightforward for solving the problem of determining if two strings are anagrams, as it relies on counting character frequencies and comparing them, which is a common technique for this type of problem.
    // The algorithm effectively handles the case where the strings have different lengths by immediately returning false, and it ensures that all character counts are balanced between the two strings to confirm that they are anagrams.
    
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        
        // We create a frequency vector of size 26 to count the occurrences of each character in the strings. We iterate through both strings simultaneously, incrementing the count for characters in string s and decrementing the count for characters in string t. After processing both strings, we check if all counts in the frequency vector are zero, which would indicate that the two strings are anagrams of each other.
        vector<int> alphabets(26,0);
        
        // We iterate through both strings simultaneously, incrementing the count for characters in string s and decrementing the count for characters in string t. After processing both strings, we check if all counts in the frequency vector are zero, which would indicate that the two strings are anagrams of each other.
        for(int i = 0 ; i<s.length() ; i++){
            alphabets[s[i]-'a']++;
            alphabets[t[i]-'a']--;
        }
        
        // After processing both strings, we check if all counts in the frequency vector are zero, which would indicate that the two strings are anagrams of each other. If any count is not zero, it means that the strings have different character frequencies and are not anagrams, so we return false. If all counts are zero, we return true, confirming that the strings are anagrams.
        for(int i : alphabets){
            if(i!=0) return false;
        }
        
        // If all counts are zero, we return true, confirming that the strings are anagrams.
        return true;
    }
};