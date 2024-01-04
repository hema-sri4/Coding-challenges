/* ZERO_ADVANCE DSA BOSSCODER 
41 .First Missing Positive
link : https://leetcode.com/problems/first-missing-positive/
Given an unsorted integer array nums, return the smallest missing positive integer.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
*/
#include <bits/stdc++.h>
using namespace std;
int missingPositiveNum(int a[],int n){
    for(int i=0;i<n;i++){
        if(a[i]<=0){
            a[i]=n+1;
        }
    }
    for(int i=0;i<n;i++){
        int num=abs(a[i]);
        if(num<n){
            a[num-1]=-abs(a[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]>0){
            return i+1;
        }
    }
    return n+1;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<missingPositiveNum(a,n)<<endl;
    return 0;
}//TC : O(n) SC : O(1)