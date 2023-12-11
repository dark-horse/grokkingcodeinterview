#pragma once

using namespace std;

#include <stack>
#include <string>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/64c15ba01e1cb44fbe63ddc3 */
/*
** Given a non-negative integer represented as a string num and an integer k,
** delete k digits from num to obtain the smallest possible integer.
** Return this minimum possible integer as a string.
**
** Examples
** Input: num = "1432219", k = 3
** Output: "1219"
** Explanation: The digits removed are 4, 3, and 2 forming the new number 1219 which is the smallest.
**
** Input: num = "10200", k = 1
** Output: "200"
** Explanation: Removing the leading 1 forms the smallest number 200.
**
** Input: num = "1901042", k = 4
** Output: "2"
** Explanation: Removing 1, 9, 1, and 4 forms the number 2 which is the smallest possible.
*/

class remKDigits
{
public:
    static string removeKdigits(string num, int k)
    {
        if (k == 0) return num;
        if (num.length() == 0 || num.length() <= k) return "0";
        if (num.length() == 1) return num;

        stack<char> chars;
        chars.push(num[0]);

        for (int i = 1; i < num.length(); i++)
        {
            char ch = num[i];
            while (k > 0 && !chars.empty() && chars.top() > ch)
            {
                chars.pop();
                k--;
            }
            chars.push(ch);
        }

        while (k > 0)
        {
            chars.pop();
            k--;
        }

        string res = string(chars.size(), '\0');
        while (!chars.empty())
        {
            char ch = chars.top();
            chars.pop();
            res[chars.size()] = ch;
        }

        // remove leading 0s;
        int leading0s = 0;
        while (res[leading0s] == '0' && leading0s < res.length()) leading0s++;
        if (leading0s == res.length()) return "0";
        return leading0s ? res.substr(leading0s) : res;
    }
};