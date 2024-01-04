/* ZERO_ADVANCE DSA BOSSCODER 
75. Sort Colors
LINK : https://leetcode.com/problems/sort-colors/
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent,
with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.
Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]
*/
#include <bits/stdc++.h>
using namespace std;
void sortColors(vector<int>& nums) {
   int n=nums.size();
   int left=0,mid=0;
   int right=n-1;
   while(mid<=right){
       if(nums[mid]==0){
           swap(nums[mid],nums[left]);
           mid++;
           left++;
       }else if(nums[mid]==1){
           mid++;
       }else{
           swap(nums[mid],nums[right]);
           right--;
       }
   }
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sortColors(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}