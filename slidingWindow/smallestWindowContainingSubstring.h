#pragma once

using namespace std;

#include <string>
#include <unordered_map>

/*url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6385d9b64a29c96532f7c4e2 */

/*
** Given a string and a pattern, find the smallest substring in the given string which has all the character occurrences of the given pattern.
**
** Example 1:
** Input: String="aabdec", Pattern="abc"
** Output: "abdec"
** Explanation: The smallest substring having all characters of the pattern is "abdec"
**
** Example 2:
** Input: String="aabdec", Pattern="abac"
** Output: "aabdec"
** Explanation: The smallest substring having all characters occurrences of the pattern is "aabdec"
**
** Example 3:
** Input: String="abdbca", Pattern="abc"
** Output: "bca"
** Explanation: The smallest substring having all characters of the pattern is "bca".
**
** Example 4:
** Input: String="adcad", Pattern="abc"
** Output: ""
** Explanation: No substring in the given string has all characters of the pattern
*/

class smallestWindowContainingSubstring
{
public:
    static string findSubstring(const string& str, const string& pattern)
    {
        if (str.length() < pattern.length()) return "";
        unordered_map<char, int> patternChars = unordered_map<char, int>();
        for (int i = 0; i < pattern.length(); i++) patternChars[pattern[i]] += 1;

        int l = 0, r = 0, matched = 0, found_l = -1, found_sz = INT32_MAX;

        while (r < str.length())
        {
            char ch = str[r];
            if (patternChars.find(ch) != patternChars.end() && patternChars[ch] != 0)
            {
                matched++;
                patternChars[ch] -= 1;
            }

            while (r < str.length() - 1 && matched < pattern.length())
            {
                r++;
                ch = str[r];
                if (patternChars.find(ch) != patternChars.end())
                {
                    if (patternChars[ch] > 0) matched++;
                    patternChars[ch] -= 1;
                }
            }

            while (l <= r && matched == pattern.length())
            {
                if (r - l + 1 < found_sz)
                {
                    found_l = l;
                    found_sz = r - l + 1;
                }
                ch = str[l];
                if (patternChars.find(ch) != patternChars.end())
                {
                    if (patternChars[ch] >= 0) matched--;
                    patternChars[ch]++;
                }

                l++;
            }

            r++;
        }

        return found_l >= 0 ?  str.substr(found_l, found_sz) : "";
    }
};