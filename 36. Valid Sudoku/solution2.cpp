class Solution {
public:
    
    // The isValidSudoku function checks the validity of a Sudoku board by performing three main checks: it verifies that each row contains no duplicate digits, each column contains no duplicate digits, and each of the nine 3x3 sub-boxes contains no duplicate digits. It uses unordered sets to track the digits seen in each row, column, and sub-box. If any duplicates are found during these checks, the function returns false; if all checks pass, it returns true, indicating that the Sudoku board is valid.
    // The function iterates through each cell in the 9x9 board. For each non-empty cell, it constructs three unique strings to represent the presence of the digit in its row, column, and 3x3 box. It checks if any of these strings already exist in the unordered set, which would indicate a duplicate. If a duplicate is found, it returns false. If not, it inserts these strings into the set. If the loop completes without finding duplicates, it returns true.
    
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;

        // Iterate through each cell in the 9x9 Sudoku board. For each non-empty cell, create unique identifiers for the row, column, and 3x3 box that the digit belongs to. Check if any of these identifiers already exist in the unordered set, which would indicate a duplicate. If a duplicate is found, return false. If not, insert these identifiers into the set. If the loop completes without finding duplicates, return true.
        for(int i = 0 ; i<9 ; i++){
            
            for(int j = 0 ; j<9 ; j++){
            
                if(board[i][j] == '.') continue;
                
                // Construct unique strings to represent the presence of the digit in its row, column, and 3x3 box. The row string combines the digit with its row index, the column string combines the digit with its column index, and the box string combines the digit with the indices of the 3x3 box it belongs to (calculated using integer division by 3). These strings are used to check for duplicates in the unordered set.
                string row = string(1, board[i][j]) + "_ROW_" + to_string(i); 
                
                // The column string is constructed by combining the digit with its column index, creating a unique identifier for the presence of that digit in that specific column.
                string col = string(1, board[i][j]) + "_COLUMN_" + to_string(j);
                
                // The box string is constructed by combining the digit with the indices of the 3x3 box it belongs to, which are calculated using integer division of the row and column indices by 3. This creates a unique identifier for the presence of that digit in that specific 3x3 box.
                string box = string(1, board[i][j]) + "_BOX_" + to_string(i/3) + "_" + to_string(j/3);
                
                // Check if any of the constructed strings (row, column, box) already exist in the unordered set. If any of them do, it means there is a duplicate digit in that row, column, or box, and the function returns false. If none of them exist in the set, it means the digit is unique in its row, column, and box, and the function inserts these strings into the set for future reference.
                if(st.find(row)!=st.end() || st.find(col)!=st.end() || st.find(box)!=st.end()) return false;

                st.insert(row);
                st.insert(col);
                st.insert(box);
            }

        }
        
        return true;
    }
};