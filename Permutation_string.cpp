/* ZERO_ADVANCE DSA BOSSCODER 
567. Permutation in String
LINK : https://leetcode.com/problems/permutation-in-string/
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.
Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
*/
#include <bits/stdc++.h>
using namespace std;
bool checkInclusion(string s1, string s2) {
    vector<int> s1Count(26, 0);
    vector<int> s2Count(26, 0);
    int s1Len = s1.length();
    int s2Len = s2.length();

    if (s1Len > s2Len) {
        return false;
    }

    for (int i = 0; i < s1Len; i++) {
        s1Count[s1[i] - 'a']++;
        s2Count[s2[i] - 'a']++;
    }

    if (s1Count == s2Count) {
        return true;
    }

    for (int i = s1Len; i < s2Len; i++) {
        s2Count[s2[i] - 'a']++;
        s2Count[s2[i - s1Len] - 'a']--;

        if (s1Count == s2Count) {
            return true;
        }
    }

    return false; 
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<checkInclusion(s)<<endl;
    return 0;
}