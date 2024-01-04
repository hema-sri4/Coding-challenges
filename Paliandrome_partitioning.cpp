/* ZERO_ADVANCE DSA BOSSCODER
131. Palindrome Partitioning
LINK : https://leetcode.com/problems/palindrome-partitioning/
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.
Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:
Input: s = "a"
Output: [["a"]]
*/
#include <bits/stdc++.h>
using namespace std;
bool isPaliandrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
        {
            return false;
        }
    }
    return true;
}
void func(int index, string s, vector<string> &path, vector<vector<string>> &res)
{
    int n=s.size();
    if (index == n)
    {
        res.push_back(path);
        return;
    }
    for (int i = index; i < n; i++)
    {
        if (isPaliandrome(s, index, i))
        {
            path.push_back(s.substr(index, i - index + 1));
            func(i + 1, s, path, res);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> result;
    vector<string> path;
    func(0, s, path, result);
    return result;
}

int main()
{
    string s;
    cin >> s;
    vector<vector<string>> res = partition(s);
    for(const auto & x:res){
        for(const auto &element : x){
            cout<<element<<" ";
        }
        cout<<endl;
    }
    return 0;
}
