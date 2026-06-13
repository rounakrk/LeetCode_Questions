class NumArray {
public:
    // We can store the input array in a member variable to allow for efficient access when calculating the sum of a range.
    vector<int> arr;
    // The constructor initializes the member variable with the input array, allowing us to use it for the sumRange function.
    NumArray(vector<int>& nums) {
        // We can simply assign the input array to the member variable, which will allow us to access the elements of the array when calculating the sum of a range.
        arr = nums;
    }
    
    // The sumRange function calculates the sum of the elements in the range [left, right] by iterating through the elements in that range and adding them to a sum variable.
    int sumRange(int left, int right) {
        // We can initialize a sum variable to 0 and then use a while loop to iterate through the elements in the range [left, right], adding each element to the sum variable until we reach the end of the range.
        int sum = 0;
        // We can use a while loop to iterate through the elements in the range [left, right] and add each element to the sum variable until we reach the end of the range.
        while(left<=right){
            // We can add the current element at index left to the sum variable and then increment left to move to the next element in the range until we reach right.
            sum += arr[left];
            left++;
        }
        // After the while loop, we can return the sum variable, which will contain the total sum of the elements in the range [left, right].
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */