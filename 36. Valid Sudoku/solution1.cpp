class Solution {
public:

    // This function checks if the 3x3 sub-box defined by the starting row (sr), starting column (sc), ending row (er), and ending column (ec) contains any duplicate numbers. It uses an unordered set to track the numbers seen in the sub-box. If a duplicate is found, it returns false; otherwise, it returns true after checking all cells in the sub-box.
    // The main function, isValidSudoku, first checks each row and column for duplicates using a similar approach with unordered sets. Then, it iterates through the 3x3 sub-boxes by incrementing the starting row and column by 3, calling the traverseBoard function for each sub-box. If any of these checks fail, it returns false; if all checks pass, it returns true, indicating that the Sudoku board is valid.
    bool traverseBoard(vector<vector<char>>& board, int sr, int sc, int er, int ec){
        unordered_set<char> st;
        // Iterate through the cells in the specified 3x3 sub-box defined by the starting row (sr), starting column (sc), ending row (er), and ending column (ec). For each cell, if it contains a digit (not '.'), check if it has already been seen in the unordered set. If it has, return false, indicating a duplicate. If not, add the digit to the set. If the loop completes without finding duplicates, return true.
        for(int i = sr; i<=er; i++){
            for(int j = sc; j<=ec; j++){
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j])!=st.end()) return false;
                st.insert(board[i][j]);
            }
        }
        return true;
    }

    // The isValidSudoku function checks the validity of a Sudoku board by performing three main checks: it verifies that each row contains no duplicate digits, each column contains no duplicate digits, and each of the nine 3x3 sub-boxes contains no duplicate digits. It uses unordered sets to track the digits seen in each row, column, and sub-box. If any duplicates are found during these checks, the function returns false; if all checks pass, it returns true, indicating that the Sudoku board is valid.
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check each row for duplicates
        for(int row = 0; row<9;row++){
            unordered_set<char> st;
            for(int col = 0; col<9; col++){
                if(board[row][col] == '.') continue;
                if(st.find(board[row][col])!=st.end()) return false;
                st.insert(board[row][col]);
            }
        }
        // Check each column for duplicates
        for(int col = 0; col<9;col++){
            unordered_set<char> st;
            for(int row = 0; row<9; row++){
                if(board[row][col] == '.') continue;
                if(st.find(board[row][col])!=st.end()) return false;
                st.insert(board[row][col]);
            }
        }
        // Check each 3x3 sub-box for duplicates by iterating through the starting rows and columns in increments of 3, calling the traverseBoard function for each sub-box. If any sub-box contains duplicates, return false. If all checks pass, return true.
        for(int sr = 0 ; sr<9 ; sr+=3){
            int er = sr + 2;
            for(int sc = 0 ; sc < 9 ; sc+=3){
                int ec = sc + 2;
                if(!traverseBoard(board, sr, sc, er, ec)) return false;
            }
        }

        return true;
    }
};