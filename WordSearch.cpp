/* ZERO_ADVANCE DSA BOSSCODER 
79. Word Search
link : https://leetcode.com/problems/word-search/
solution : https://www.youtube.com/watch?v=4QjCc7HeR8s&t=400s&ab_channel=CuriousChahar
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are 
horizontally or vertically neighboring. The same letter cell may not be used more than once.
Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
*/
#include <bits/stdc++.h>
using namespace std;
bool helper(vector<vector<char>>& board, string word,int i,int j,int row,int col,int k){
    if(k>=word.size()){
        return true;
    }
    if(i<0 || i>=row || j<0 || j>=col || board[i][j]=='.' || word[k]!=board[i][j]){
        return false;
    }
    if(word.size()==1 && board[i][j]==word[k]){
        return true;
    }
    board[i][j]='.';
    bool temp=false;
    int x[4]={0,0,-1,1};
    int y[4]={-1,1,0,0};
    for(int index=0;index<4;index++){
        temp= temp || helper(board,word,i+x[index],j+y[index],row,col,k+1);
    }
    board[i][j]=word[k];
    return temp;
}
bool exist(vector<vector<char>>& board, string word) {
    int row=board.size();
    int col=board[0].size();
    if(row==0 || word.size()==0){
        return false;
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(word[0]==board[i][j]){
                if(helper(board,word,i,j,row,col,0)){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    int row,col;
    cin>>row>>col;
    vector<vector<char>> board(row,vector<char>(col));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>board[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    string word;
    cin>>word;
    cout<<exist(board,word)<<endl;
  return 0;
}
