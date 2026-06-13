class Solution {
public:
    // Encodes a list of strings to a single string.
    // The encoded string is then sent over the network and is decoded back to the original list of strings.
    // The string may contain any possible characters out of 256 valid ascii characters.
    // Your algorithm should be generalized enough to work on any possible characters and a list of strings of any length.
    string encode(vector<string>& strs) {
        string result = "";
        for(string s : strs){
            // We can use the length of the string followed by a special character (e.g., '#') to separate 
            // the length from the string itself. This way, we can easily decode it later.
            result += to_string(s.size()) + "#" + s;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    // The encoded string is guaranteed to be valid.
    // So we can just follow the encoding format to decode it back to the original list of strings.
    // We can use the length of the string to determine how many characters to read for each string in the list.
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        // We can use a while loop to iterate through the encoded string and decode each string in the list 
        // until we reach the end of the encoded string.
        while(i < s.size()){
            // We can find the index of the special character (e.g., '#') to 
            // determine where the length of the string ends and where the string itself starts.
            int j = s.find('#', i);

            // We can use the substring from the current index to the index of the special character to get the length of the string.
            int length = stoi(s.substr(i, j - i));
            // We can then update the index to point to the start of the string itself, which is right after the special character.
            i = j + 1;
            // We can use the length of the string to read the correct number of characters for the string itself and add it to the result list.
            result.push_back(s.substr(i, length));

            i += length;
        }
        return result;
    }
};
