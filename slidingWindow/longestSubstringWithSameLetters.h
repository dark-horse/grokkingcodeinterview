#pragma once

using namespace std;

#include <iostream>
#include <set>
#include <map>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6385d4b24a29c96532f7bb19 */
/*
** Given a string with lowercase letters only, if you are allowed to replace no more than ‘k’ letters with any letter,
** find the length of the longest substring having the same letters after replacement.

** Example 1:
** Input: String="aabccbb", k=2
** Output: 5
** Explanation: Replace the two 'c' with 'b' to have a longest repeating substring "bbbbb".
**
** Example 2:
** Input: String="abbcb", k=1
** Output: 4
** Explanation: Replace the 'c' with 'b' to have a longest repeating substring "bbbb".
**
** Example 3:
** Input: String="abccde", k=1
** Output: 3
** Explanation: Replace the 'b' or 'd' with 'c' to have the longest repeating substring "ccc".
*/

class longestSubstringWithSameLetters
{
public:
    static int findLength(const string& str, int k)
    {
        if (str.length() <= 1) return str.length();

        char wndChars[CHAR_MAX + 1]{ 0 };    // assume all chars are greater than 0 (for example all digits and numbers)

        int l = 0, r = 0, len = 0;
        char popCh = '\0';

        while (r < str.length())
        {
            popCh = updateWndChars(wndChars, str[r], popCh, true);
            while (r < str.length() - 1 && k + wndChars[popCh] >= r - l + 1)
            {
                int newLen = r - l + 1;
                len = newLen > len ? newLen : len;
                r++;
                popCh = updateWndChars(wndChars, str[r], popCh, true);
            }

            if (k + wndChars[popCh] >= r - l + 1)
            {
                int newLen = r - l + 1;
                len = newLen > len ? newLen : len;
            }

            while (l <= r && k + wndChars[popCh] < r - l + 1)
            {
                popCh = updateWndChars(wndChars, str[l], popCh, false);
                l++;
            }

            r++;
        }

        return len;
    }

private:
    // this function will return the index of the most "popular" char in wndChars
    static char updateWndChars(char* wndChars, char ch, char currPopCh, bool add)
    {
        wndChars[ch] += add ? 1 : -1;
        if (add)
        {
            return wndChars[currPopCh] >= wndChars[ch] ? currPopCh : ch;
        }
        else
        {
            if (ch != currPopCh)
            {
                // deleted a char that was not the most popular. That does not change the most popular char
                return currPopCh;
            }
            else
            {
                // Deleted the most popular char.
                // loop through all the chars to find the new most popular char.
                // This loop assumes only characters larger than '\0' are used (like digits and letters).
                // (the fix is to use unsigned chars...)
                // How can we make it faster?
                int maxFreq = 0;
                char popCh = '\0';
                for (char chIndex = '\0'; chIndex < CHAR_MAX; chIndex++)
                {
                    if (wndChars[chIndex] > maxFreq)
                    {
                        maxFreq = wndChars[chIndex];
                        popCh = chIndex;
                    }
                }
                return popCh;
            }
        }
    }
};