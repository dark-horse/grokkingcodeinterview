#pragma once

using namespace std;

#include <vector>
#include <iostream>
#include <unordered_map>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6384513a635674508787c7c3 */

/*
** Given a string, find the length of the longest substring in it with no more than K distinct characters.
** You can assume that K is less than or equal to the length of the given string.
** Example 1:
** Input: String="araaci", K=2
** Output: 4
** Explanation: The longest substring with no more than '2' distinct characters is "araa".
**
** Example 2:
** Input: String="araaci", K=1
** Output: 2
** Explanation: The longest substring with no more than '1' distinct characters is "aa".
**
** Example 3:
** Input: String="cbbebi", K=3
** Output: 5
** Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".
*/

class longestSubstringWithKCharacters
{
public:
    static int findLength(const string& str, int k)
    {
        if (str.length() <= 1) return str.length();

        int wndChars[CHAR_MAX - CHAR_MIN + 1]{ 0 };

        int l = 0, r = 0, len = 0, distinctCharsCount = 0;
        while (r < str.length())
        {
            // update the wndChars
            distinctCharsCount += updateWndChars(wndChars, str[r], true);
            while (r < str.length() - 1 && distinctCharsCount <= k)
            {
                int newLen = r - l + 1;
                len = newLen > len ? newLen : len;
                r++;
                distinctCharsCount += updateWndChars(wndChars, str[r], true);
            }

            if (distinctCharsCount <= k)
            {
                int newLen = r - l + 1;
                len = newLen > len ? newLen : len;
            }

            while (l <= r && distinctCharsCount > k)
            {
                distinctCharsCount += updateWndChars(wndChars, str[l], false);
                l++;
            }

            r++;
        }

        return len;
    }

private:
    static int updateWndChars(int* wndChars, char ch, bool add)
    {
        int res = 0;
        if (add)
        {
            if (wndChars[ch] == 0) res = 1;
            wndChars[ch] = wndChars[ch] + 1;
        }
        else
        {
            if (wndChars[ch] == 1) res = -1;
            wndChars[ch] = wndChars[ch] - 1;
        }

        return res;
    }
};