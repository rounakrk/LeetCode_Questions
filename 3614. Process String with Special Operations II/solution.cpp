class Solution {
public:

    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // Approach: We can iterate through the string and keep track of the length of the processed string.
    // If we encounter a '*', we decrement the length by 1. If we encounter
    // a '#', we double the length. If we encounter a '%', we do nothing. If we encounter any other character, we increment the length by 1.
    // If k is greater than or equal to the length of the processed string, we return '.'. Otherwise, we iterate through the string in reverse and keep track of the length of the processed string.
    // If we encounter a '*', we increment the length by 1. If we encounter
    // a '%', we set k to be the length of the processed string minus k minus 1. If we encounter a '#', we halve the length and set k to be k minus the length if k is greater than or equal to the length. If we encounter any other character, we decrement the length by 1.
    // If k is equal to the length of the processed string, we return the character. If we finish iterating through the string and do not find the character, we return '.'.

    char processStr(string s, long long k) {
        long long L = 0;
        int n = s.size();

        for (char &ch : s){
            if(ch == '*'){
                if(L > 0) L--;
            }else if(ch == '#') L *= 2;
            else if(ch == '%') continue;
            else L++;
        }

        if(k >= L) return '.';

        for(int i = n-1; i >= 0; i--){
            if(s[i] == '*'){
                L++;
            }else if(s[i] == '%'){
                k = L - k - 1;
            }else if(s[i] == '#'){
                L = L/2;
                k = (k >= L) ? k - L : k;
            }else{
                L--;
            }

            if(k == L) return s[i];
        }

        return '.';
    }
};