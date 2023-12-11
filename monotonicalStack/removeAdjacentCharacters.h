#pragma once

using namespace std;

#include <string>
#include <stack>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/64c0f4899d852050755badbe */

/*
** Given a string S, remove all adjacent duplicate characters recursively to generate the resultant string.
** 
** Examples
** Input: s = "abccba"
** Output: ""
** Explanation: First, we remove "cc" to get "abba". Then, we remove "bb" to get "aa". Finally, we remove "aa" to get an empty string.
**
** Input: s = "foobar"
** Output: "fbar"
** Explanation: We remove "oo" to get "fbar".
**
** Input: s = "abcd"
** Output: "abcd"
** Explanation: No adjacent duplicates so no changes.
*/

class remAdjChars
{
public:
    static string removeDuplicates(string s)
    {
        stack<char> chars;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (!chars.empty() && chars.top() == ch)
            {
                chars.pop();
            }
            else
            {
                chars.push(ch);
            }
        }

        string res(chars.size(), '\0');

        while (!chars.empty())
        {
            res[chars.size() - 1] = chars.top();
            chars.pop();
        }

        return res;
    }
};