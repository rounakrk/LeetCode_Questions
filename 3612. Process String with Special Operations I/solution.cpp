class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // Approach: We can iterate through the string and perform the operations based on the characters. 
    // If the character is a lowercase letter, we can add it to the result string. 
    // If the character is '#', we can double the result string. 
    // If the character is '%', we can reverse the result string. 
    // If the character is '*', we can remove the last character from the result string if it is not empty. 
    // Finally, we can return the result string.

    string processStr(string s) {
        string result = "";
        for(char a : s){
            string c{a};
            if (c >= "a" && c <= "z"){
                // result += to_string(c);
                result += c;
            }else if(c == "#"){
                result += result;
            }else if(c == "%"){
                reverse(result.begin(), result.end());
            }else if(c == "*"){
                if(result != "") result.pop_back();
            }else continue;
        }

        return result;
    }
};