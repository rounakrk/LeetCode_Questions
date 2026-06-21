class Solution {
public:

    // Time Complexity: O(1)
    // Space Complexity: O(1)
    // Explanation: The angle between the hour hand and the minute hand can be calculated using the formula:
    // Angle = |(60 * hour - 11 * minutes) / 2|
    // If the calculated angle is greater than 180 degrees, we can find the smaller angle
    // by subtracting the calculated angle from 360 degrees.
    // This approach ensures that we always return the smaller angle between the two hands of the clock.
    // The time complexity is O(1) because we are performing a constant number of operations, and the space complexity is O(1) because we are using a constant amount of space to store the result.
    // This solution is efficient and straightforward, making it easy to understand and implement.
    // Overall, this method provides a clear and concise way to calculate the angle between the hour and minute hands of a clock based on the given time.
    // This solution is optimal for this problem as it directly computes the angle using a simple mathematical formula without the need for any loops or additional data structures.

    double angleClock(int hour, int minutes) {
        double result = abs((double)(60* hour - 11*minutes) / 2);
        if(result>180) return 360.00 - result;
        return result;

    }
};