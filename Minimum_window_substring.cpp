/* ZERO_ADVANCE DSA BOSSCODER
76. Minimum Window Substring
LINK : https://leetcode.com/problems/minimum-window-substring/
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in the window. 
If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/
#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) {
    int m=s.length(),n=t.length();
    if(n>m){
        return "";
    }
    unordered_map<char,int>mp;
    for(char & c:t){
        mp[c]++;
    }
    int reqcount=n;
    int minWindowsize=INT_MAX;
    int i=0,j=0,start_i=0;
    while(j<m){
        char ch=s[j];
        if(mp[ch]>0){
            reqcount--;
        }
        mp[ch]--;
        while(reqcount==0){
            int currwindowsize=j-i+1;
            if(minWindowsize>currwindowsize){
                minWindowsize=currwindowsize;
                start_i=i;
            }
            mp[s[i]]++;
            if(mp[s[i]]>0){
                reqcount++;                    
            }
            i++;
        }
        j++;
    }
    return minWindowsize==INT_MAX ? "":s.substr(start_i,minWindowsize);
}
int main()
{
    string s1,s2;
    cin >> s1>>s2;
    cout<<minWindow(s1,s2)<<endl;
    return 0;
}