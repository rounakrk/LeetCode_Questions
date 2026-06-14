class NumMatrix {
public:
    // tarr[i+1][j+1] = matrix[i][j] + tarr[i+1][j] + tarr[i][j+1] - tarr[i][j]; 
    vector<vector<int>> tarr;
    // tarr[i+1][j+1] represents the sum of all elements in the submatrix from (0,0) to (i,j)
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        tarr.resize(n+1, vector<int>(m+1,0));
        // 1. Current cell total = Current original value + Top neighbor + Left neighbor.
        // 2. Subtract the Top-Left diagonal neighbor because it was double-counted by the Top and Left neighbors.
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ; j++){
                tarr[i+1][j+1] = matrix[i][j] + tarr[i+1][j] + tarr[i][j+1] - tarr[i][j];
            }
        }
    }
    
    // 1. Target Sum = Entire big box area minus the unwanted Top Strip and Left Strip.
    // 2. Add back the Top-Left corner piece because subtracting both strips cut it out twice.
    int sumRegion(int row1, int col1, int row2, int col2) {
        return tarr[row2+1][col2+1] - tarr[row2+1][col1] - tarr[row1][col2+1] + tarr[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */