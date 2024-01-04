/* ZERO_ADVANCE DSA BOSSCODER
84. Largest Rectangle in Histogram
link : https://leetcode.com/problems/largest-rectangle-in-histogram/
solution : https://leetcode.com/problems/largest-rectangle-in-histogram/solutions/732697/44ms-easy-solution-c/
actual sol1: https://www.youtube.com/watch?v=X0X6G-eWgQ8&ab_channel=takeUforward
sol2: https://www.youtube.com/watch?v=jC_cWLy7jSI&t=12s&ab_channel=takeUforward
Given an array of integers heights representing the histogram's bar height where
the width of each bar is 1, return the area of the largest rectangle in the histogram.
Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Example 2:
Input: heights = [2,4]
Output: 4
*/
#include <bits/stdc++.h>
using namespace std;
int largerarea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int leftsmall[n], rightsmall[n];
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
            leftsmall[i] = 0;
        else
            leftsmall[i] = st.top() + 1;
        st.push(i);
    }
    while (!st.empty())
    {
        st.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        if (st.empty())
            rightsmall[i] = n - 1;
        else
            rightsmall[i] = st.top() - 1;

        st.push(i);
    }
    int maxA = 0;
    for (int i = 0; i < n; i++)
    {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
    }
    return maxA;
} // tc : o(n) sc: o(3n)
int largestarea(vector<int> &a)
{
    int area = 0;
    stack<int> st;
    a.push_back(0);
    for (int i = 0; i < a.size(); i++)
    {
        while (!st.empty() && a[st.top()] > a[i])
        {
            int top = a[st.top()];
            st.pop();
            int check = st.empty() ? -1 : st.top();
            area = max(area, top * (i - check - 1));
        }
        st.push(i);
    }
    return area;
} // tc : o(n)+o(n) sc : o(n)
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << largestarea(arr) << endl;
}
