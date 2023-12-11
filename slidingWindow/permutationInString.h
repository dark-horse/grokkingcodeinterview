#pragma once

using namespace std;

#include <iostream>

/* https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6385d76c4a29c96532f7c16b */
/*
** Given a string and a pattern, find out if the string contains any permutation of the pattern.
** Permutation is defined as the re-arranging of the characters of the string. For example, “abc” has the following six permutations:
** abc, acb, bac, bca, cab, cba
** If a string has ‘n’ distinct characters, it will have n! permutations.
**
** Example 1:
** Input: String="oidbcaf", Pattern="abc"
** Output: true
** Explanation: The string contains "bca" which is a permutation of the given pattern.
**
** Example 2:
** Input: String="odicf", Pattern="dc"
** Output: false
** Explanation: No permutation of the pattern is present in the given string as a substring.
**
** Example 3:
** Input: String="bcdxabcdy", Pattern="bcdyabcdx"
** Output: true
** Explanation: Both the string and the pattern are a permutation of each other.
**
** Example 4:
** Input: String="aaacb", Pattern="abc"
** Output: true
** Explanation: The string contains "acb" which is a permutation of the given pattern.
*/

class permutationInString
{
public:
    static bool findPermutation(const string& str, const string& pattern)
    {
        if (str.length() < pattern.length()) return false;

        int patternCharCount[CHAR_MAX + 1]{ 0 };
        int subStrCharCount[CHAR_MAX + 1]{ 0 };

        int hash = 0;
        for (int i = 0; i < pattern.length(); i++)
        {
            patternCharCount[pattern[i]] += 1;
        }
        for (int i = 0; i < pattern.length() - 1; i++)
        {
            subStrCharCount[str[i]] += 1;
        }

        for (int i = 0; i <= CHAR_MAX; i++)
        {
            hash += abs(patternCharCount[i] - subStrCharCount[i]);
        }

        int l = 0, r = pattern.length() - 1;
        while (r < str.length())
        {
            // add str[r] to the hash.
            char ch = str[r];
            hash -= abs(patternCharCount[ch] - subStrCharCount[ch]);
            subStrCharCount[ch] += 1;
            hash += abs(patternCharCount[ch] - subStrCharCount[ch]);

            if (hash == 0) return true;

            // remove str[l] from the hash
            ch = str[l];
            hash -= abs(patternCharCount[ch] - subStrCharCount[ch]);
            subStrCharCount[ch] -= 1;
            hash += abs(patternCharCount[ch] - subStrCharCount[ch]);
            l++;

            r++;
        }

        return false;
    }
};