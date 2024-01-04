/* ZERO_ADVANCE DSA BOSSCODER 
36. Valid Sudoku
link : https://leetcode.com/problems/valid-sudoku/
solution : https://www.youtube.com/watch?v=dGZjzA9zLW8&ab_channel=codestorywithMIK
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be 
validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
Example 1:
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
*/
#include <bits/stdc++.h>
using namespace std;
bool validSub(vector<vector<char>>& board, int sr, int er, int sc, int ec) {
    unordered_set<char> st;
    for(int row = sr; row<=er; row++) {
        for(int col = sc; col <= ec; col++) {
            char ch = board[row][col];
            if(ch == '.') continue;
            if(st.count(ch)) return false;
            st.insert(ch);
        }
    }
    return true;
}
bool isValidSudoku(vector<vector<char>>& board) {
    for(int row = 0; row<9; row++) {
        unordered_set<char> st;
        for(int col = 0; col <9; col++) {
            char ch = board[row][col];
            if(ch == '.') continue;
            if(st.count(ch)) return false;
            st.insert(ch);
        }
    }
    for(int col = 0; col<9; col++) {
        unordered_set<char> st;
        for(int row = 0; row <9; row++) {
            char ch = board[row][col];
            if(ch == '.') continue;
            if(st.count(ch)) return false;
            st.insert(ch);
        }
    }
    
    for(int sr = 0; sr < 9; sr+=3) {
        int er = sr+2;
        for(int sc = 0; sc < 9; sc+=3) {
            int ec = sc+2;
            if(!validSub(board, sr, er, sc, ec))
                return false;
        }
    }
    
    return true;
}
bool isValidSudoku2(vector<vector<char>>& board) {
    unordered_set<string>st;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                continue;
            }
            string row=string(1,board[i][j])+"row"+to_string(i);
            string col=string(1,board[i][j])+"col"+to_string(j);
            string box=string(1,board[i][j])+"box"+to_string(i/3)+to_string(j/3);
            if(st.count(row)||st.count(col)||st.count(box)){
                return false;
            }
            st.insert(row);
            st.insert(col);
            st.insert(box);
        }
    }
    return true;
}
int main(){
    vector<vector<char>> grid(9,vector<char>(9));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>grid[i][j];
        }
    }
    cout<<isValidSudoku(grid)<<endl;
    cout<<isValidSudoku2(grid)<<endl;
}