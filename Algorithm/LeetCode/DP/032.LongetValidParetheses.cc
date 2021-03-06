/* Hard
Given a string containing just the characters '(' and ')', find the length of the longest
    valid (well-formed) parentheses substring.

Example 1:
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()" */

#include <string>
#include <stack>
#include <algorithm>

using namespace std;

/* Using stack
 * O(N) O(N) */
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        stack<int> stk;
        stk.push(-1); // -1 0 1 2 3
        int lenMax = 0;

        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    lenMax = max(lenMax, i-stk.top());
                }
            }
        }

        return lenMax;
    }
};

/* DP
 * O(N) O(N) */
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        int dp[s.size()];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};