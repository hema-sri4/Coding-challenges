/* ZERO_ADVANCE DSA BOSSCODER 
1. Two Sum
LINK : https://leetcode.com/problems/two-sum/
Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution,
 and you may not use the same element twice.
You can return the answer in any order.
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]*/
#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& arr,int target){
    int n=arr.size();
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int compli=target-arr[i];
        if(mp.find(compli)!=mp.end()){
            return {i,mp[compli]};
        }else{
            mp[arr[i]]=i;
        }
    }
    return {};
}
int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>result=twoSum(a,target);
    int m=result.size();
    for(int i=0;i<m;i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}