class NumArray {
public:
    // We can store the input array in a member variable to allow for efficient access when calculating the sum of a range.
    vector<int> arr;
    // The constructor initializes the member variable with the input array, allowing us to use it for the sumRange function.
    NumArray(vector<int>& nums) {
        arr.resize(nums.size());
        // We can use a prefix sum array to store the cumulative sums of the input array, which will allow us to calculate the sum of any range in constant time.
        arr[0] = nums[0];
        // We can iterate through the input array and fill the prefix sum array by adding the current element to the cumulative sum of the previous elements.
        for(int i = 1; i < nums.size(); i++){
            arr[i] = nums[i] + arr[i-1];
        }
    }
    
    // The sumRange function calculates the sum of the elements in the range [left, right] using the prefix sum array. If left is 0, we can simply return the value at index right in the prefix sum array. Otherwise, we can return the difference between the values at index right and index left-1 in the prefix sum array to get the sum of the range.
    int sumRange(int left, int right) {
        // If left is 0, we can simply return the value at index right in the prefix sum array, which will give us the sum of the range from index 0 to index right.
        if(left == 0) return arr[right];
        // If left is not 0, we can return the difference between the values at index right and index left-1 in the prefix sum array to get the sum of the range from index left to index right.
        return arr[right] - arr[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */