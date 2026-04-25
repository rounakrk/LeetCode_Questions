class Solution {
public:
    // Binary Search
    // Time Complexity: O(m*log(n))
    // Space Complexity: O(1)
    // Runtime: 4 ms, faster than 99.97% of C++ online submissions for Search a 2D Matrix.
    bool findNum(vector<int>& arr, int val){
        int start = 0;
        int end = arr.size();
        int mid;
        while(start<end){
            mid = start + (end-start)/2;
            if(arr[mid]==val) return true;
            if(val>arr[mid])start = mid+1;
            else end = mid - 1;
        }
        mid = start + (end-start)/2;
        if(arr[mid]==val) return true;
        return false;
    }

    // Time Complexity: O(m+n)
    // Space Complexity: O(1)
    // Runtime: 4 ms, faster than 99.97% of C++ online
    // submissions for Search a 2D Matrix.
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = 0;
        if(m>0) n = matrix[0].size();
        bool r = false;
        for(int i = 0; i<m; i++){
            if(target>=matrix[i][0] && target<=matrix[i][n-1]){
                r = findNum(matrix[i], target);
                return r;
            }
        }
        return r;
    }
};