class Solution {
public:
    // Time Complexity: O(m+n) where m and n are the sizes of nums1 and nums2 respectively.
    // Space Complexity: O(1) as we are using only a constant amount of extra space.
    // Approach: We can use two pointers to traverse both arrays. We start with the first pointer at the beginning of nums1 and the second pointer at the beginning of nums2. We compare the values at these pointers. If the value in nums1 is less than or equal to the value in nums2, we calculate the distance and update our maximum distance if necessary, then move the second pointer forward. If the value in nums1 is greater than the value in nums2, we move the first pointer forward. We continue this process until we reach the end of either array.
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int m = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        while(i<n1 && j<n2){
            if(nums1[i] <= nums2[j]){
                m = max(m, j-i);
                j++;
            }else{
                i++;
            }
        }
        return m;
    }
};