/* ZERO_ADVANCE DSA BOSSCODER 
22. Generate Parentheses
link : https://leetcode.com/problems/generate-parentheses/description/
solution : https://www.youtube.com/watch?v=WW1rYrR3tTI&t=917s&ab_channel=CodewithAlisha
Given n pairs of parentheses, write a function to generate all combinations 
of well-formed parentheses.
Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:
Input: n = 1
Output: ["()"]
*/
#include <bits/stdc++.h>
using namespace std;
void func(vector<string> &ans,int n,int open,int close,string curr_str){
    int str_len=curr_str.size();
    if(str_len==n*2){
        ans.push_back(curr_str);
        return;
    }
    if(open<n){
        func(ans,n,open+1,close,curr_str+"(");
    }
    if(close<open){
        func(ans,n,open,close+1,curr_str+")");
    }

}
vector<string> generateParenthesis(int n) {
  vector<string> res;
  func(res,n,0,0,"");
  return res;
}
int main(){
    int n;
    cin>>n;
    vector<string> result=generateParenthesis(n);
    for (const string &str : result) {
        cout << str << endl;
    }
    return 0;
}