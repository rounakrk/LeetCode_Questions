class Solution {
public:
    //  Function to rearrange the array elements by sign.
    // The function takes an array as input and returns a new array with positive and negative elements rearranged.
    // Time Complexity: O(n), where n is the size of the input array. We traverse the array once to separate positive and negative elements, and then we combine them back into a new array.
    // Space Complexity: O(n), where n is the size of the input array. We use three additional vectors to store the positive and negative elements separately, and then combine them back into a new array, which can take up to O(n) space in the worst case (when all elements are either positive or negative).
    vector<int> rearrangeArray(vector<int>& nums) {
       
        vector<int> a;
        vector<int> b;
        vector<int> c;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        for(int i=0;i<nums.size()/2; i++){
            c.push_back(a[i]);
            c.push_back(b[i]);
        }
        return c;
    }

    // Function to rearrange the array elements by sign using a more efficient approach.
    // The function takes an array as input and returns a new array with positive and negative elements
    // rearranged without using extra space for separate vectors.
    // Time Complexity: O(n), where n is the size of the input array. We
    // traverse the array once to rearrange the elements in-place.
    // Space Complexity: O(1), as we are rearranging the elements in-place without using extra space for separate vectors.
    vector<int> rearrangeArray2(vector<int>& nums) {
       int n = nums.size();
       vector<int> ans(n);
       int even = 0;
       int odd = 1;
       for(int i=0;i<n;i++){
        if(nums[i]>=0){
            ans[even] = nums[i];
            even+=2;
        }else{
            ans[odd] = nums[i];
            odd+=2;
        }
       }
       return ans;
    }
};