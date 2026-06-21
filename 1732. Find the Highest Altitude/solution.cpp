class Solution {
public:

    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // Explanation: We initialize two variables, alt and currentAlt, to keep track of the highest altitude and the current altitude respectively.
    // We iterate through the gain vector, adding each gain value to currentAlt to calculate the new altitude after each gain.
    // We then update alt to be the maximum of the current alt and the new currentAlt.
    // This approach ensures that we efficiently calculate the highest altitude reached during the trip in O(n) time, where n is the number of gain values.
    // The space complexity is O(1) because we are using a constant amount of space to store the alt and currentAlt variables, regardless of the size of the input vector.
    // This solution is efficient and straightforward, making it easy to understand and implement.
    // Overall, this method provides a clear and concise way to find the highest altitude reached during
    // the trip based on the given gain values.

    int largestAltitude(vector<int>& gain) {
        int alt = 0;
        int currentAlt = 0;
        for(int i : gain){
            currentAlt += i;
            alt = max(alt, currentAlt);
        }
        return alt;
    }
};