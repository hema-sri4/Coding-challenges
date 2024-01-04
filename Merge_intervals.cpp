/* ZERO_ADVANCE DSA BOSSCODER 
56. Merge Intervals
LINK : https://leetcode.com/problems/merge-intervals/
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.
Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> & intervals){
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    int n = intervals.size();
    for(int i = 0; i < n; i++){
        int start = intervals[i][0];
        int end = intervals[i][1];
        while(i < n - 1 && intervals[i + 1][0] <= end){
            end = max(end, intervals[i + 1][1]);
            i++;
        }
        res.push_back({start, end});
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<=1;j++){
            cin>>a[i][j];
        }
    }
    cout<<endl;
    vector<vector<int>> result=merge(a);
    int r=result.size();
    for(int i=0;i<r;i++){
        for(int j=0;j<=1;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    } 
    return 0;
}