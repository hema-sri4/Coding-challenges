/* ZERO_ADVANCE DSA BOSSCODER 
18. 4Sum
LINK : https://leetcode.com/problems/4sum/
Given an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
   vector<vector<int>> res;
   int n=nums.size();
   sort(nums.begin(),nums.end());
   for(int i=0;i<n;i++){
       if(i>0 && nums[i]==nums[i-1]) continue;
       for(int j=i+1;j<n;j++){
           if(j!=i+1 && nums[j]==nums[j-1]) continue;
           int k=j+1;
           int l=n-1;
           while(k<l){
               long long sum=nums[i];
               sum+=nums[j];
               sum+=nums[k];
               sum+=nums[l];
               if(sum>target){
                   l--;
               }else if(sum<target){
                   k++;
               }else{
                  vector<int> t={nums[i],nums[j],nums[k],nums[l]}; 
                  res.push_back(t);
                  k++;
                  l--;
                  while(k<l && nums[k]==nums[k-1]) k++;
                  while(k<l && nums[l]==nums[l+1]) l--;
               }
           }
       }
   } 
   return res;
}
int main(){
    int n,target;
    cin>>n>>target;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>>res =fourSum(a,target);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}