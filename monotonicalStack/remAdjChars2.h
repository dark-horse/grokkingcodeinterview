#pragma once

using namespace std;

#include <string>
#include <stack>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/64c14baaee20248bcc6d1d4c */
/*
** You are given a string s and an integer k. Your task is to remove groups of identical,
** consecutive characters from the string such that each group has exactly k characters.
** The removal of groups should continue until it's no longer possible to make any more removals.
** The result should be the final version of the string after all possible removals have been made.
**
** Examples
**
** Input: s = "abbbaaca", k = 3
** Output: "ca"
** Explanation: First, we remove "bbb" to get "aaaca". Then, we remove "aaa" to get "ca".
**
** Input: s = "abbaccaa", k = 3
** Output: "abbaccaa"
** Explanation: There are no instances of 3 adjacent characters being the same.
**
** Input: s = "abbacccaa", k = 3
** Output: "abb"
** Explanation: First, we remove "ccc" to get "abbaaa". Then, we remove "aaa" to get "abb".
*/

class remAdjChars2
{
public:
    static string removeDuplicates(string s, int k)
    {

        if (s.length() <= 1 || s.length() < k) return s;

        if (k == 1) return "";

        stack<pair<char, int>> chars;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (!chars.empty() && chars.top().first == ch)
            {
                if (chars.top().second == k - 1)
                {
                    while (!chars.empty() && chars.top().first == ch) chars.pop();
                }
                else
                {
                    chars.push(make_pair(ch, chars.top().second + 1));
                }
            }
            else
            {
                chars.push(make_pair(ch, 1));
            }
        }

        string res(chars.size(), '\0');

        while (!chars.empty())
        {
            res[chars.size() - 1] = chars.top().first;
            chars.pop();
        }

        return res;
    }
};