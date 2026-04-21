class Solution {
  public:
    //   Function to move all negative elements to end of array.
    //   The order of elements is important here.
    //   The function takes an array as input and modifies the array in-place.
    //   The extra space is used for storing the positive and negative elements separately, and then combining them back into the original array.
    //   Time Complexity: O(n), where n is the size of the input array. We traverse the array once to separate positive and negative elements, and then we combine them back into the original array.
    //   Space Complexity: O(n), where n is the size of the input array. We use two additional vectors to store the positive and negative elements, which can take up to O(n) space in the worst case (when all elements are either positive or negative).
    //   Note: The space complexity can be optimized to O(1) by using a two-pointer approach to rearrange the elements in-place without using extra space for separate vectors.
    void segregateElements(vector<int>& arr) {
        vector<int> a;
        vector<int> b;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0) a.push_back(arr[i]);
            else b.push_back(arr[i]);
        }
        a.insert(a.end(), b.begin(), b.end());
        arr = a;
    }
};