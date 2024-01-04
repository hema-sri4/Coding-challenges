/* ZERO_ADVANCE DSA BOSSCODER 
1249. Minimum Remove to Make Valid Parentheses
LINK : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
Given a string s of '(' , ')' and lowercase English characters.
Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
Formally, a parentheses string is valid if and only if:
It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Example 1:
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:
Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
*/
#include <bits/stdc++.h>
using namespace std;
string minRemoveToMakeValid(string s) {
    int cnt=0;
    for(char &c: s){
        if(c=='('){ cnt++;}
        else if(c==')'){
            if(cnt==0) c='*';
            else cnt--;
        }
    }
    cnt=0;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]==')') {cnt++;}
        else if(s[i]=='('){
            if(cnt==0) s[i]='*';
            else cnt--;
        }
    }
    s.erase(remove(s.begin(),s.end(),'*'),s.end());
    return s;
}
int main(){
    string s;
    cin>>s;
    cout<<minRemoveToMakeValid(s)<<endl;
    return 0;
}//TC : O(n) SC : O(1)