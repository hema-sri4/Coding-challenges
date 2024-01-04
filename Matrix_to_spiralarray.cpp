/* ZERO_ADVANCE DSA BOSSCODER 
54. Spiral Matrix 
link : https://leetcode.com/problems/spiral-matrix/
Given an m x n matrix, return all elements of the matrix in spiral order.
Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> spiralMatrix(vector<vector<int>> &matrix) {
    vector<int> res;
    int row=matrix[0].size(),column=matrix.size();
    int left=0,up=0,right=row-1,down=column-1;
    while(res.size()<row*column){
        for(int i=left;i<=right && res.size()<row*column;i++){
            res.push_back(matrix[up][i]);
        }
        for(int i=up+1;i<=down-1 && res.size()<row*column;i++){
            res.push_back(matrix[i][right]);
        }
        for(int i=right;i>=left && res.size()<row*column;i--){
            res.push_back(matrix[down][i]);
        }
        for(int i=down-1;i>=up+1 && res.size()<row*column;i--){
            res.push_back(matrix[i][left]);               
        }
        left++;right--;
        up++;down--;                                    
    }
    return res;
}
int main(){
    int row,column;
    cin>>row>>column;
    vector<vector<int>> a(row,vector<int>(column));
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cin>>a[i][j];
        }
    }
    vector<int> res=spiralMatrix(a);
    for(int i=0;i<row*column;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
