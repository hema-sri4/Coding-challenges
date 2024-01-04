/* ZERO_ADVANCE DSA BOSSCODER
78. Subsets
LINK :https://leetcode.com/problems/subsets/
Given an integer array nums of unique elements, return all possible  subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:
Input: nums = [0]
Output: [[],[0]]
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>> res;
    for(int i=0;i<pow(2,n);i++){
        vector<int>v;
        for(int j=0;j<n;j++){
            if((1<<j)& i){
                v.push_back(nums[j]);
            }
        }
        res.push_back(v);
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>>res=subsets(a);
    for(auto & row:res){
        for(auto &element:row){
            cout<<element<<" ";
        }
        cout<<endl;
    }
    return 0;
}