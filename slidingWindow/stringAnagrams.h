#pragma once

using namespace std;
#include <string>
#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6385d8b24a29c96532f7c329 */
/*
** Given a string and a pattern, find all anagrams of the pattern in the given string.
** Every anagram is a permutation of a string. As we know, when we are not allowed to repeat characters
** while finding permutations of a string, we get N! permutations (or anagrams) of a string having NN characters.
** Write a function to return a list of starting indices of the anagrams of the pattern in the given string.
**
** Example 1:
** Input: String="ppqp", Pattern="pq"
** Output: [1, 2]
** Explanation: The two anagrams of the pattern in the given string are "pq" and "qp".
**
** Example 2:
** Input: String="abbcabc", Pattern="abc"
** Output: [2, 3, 4]
** Explanation: The three anagrams of the pattern in the given string are "bca", "cab", and "abc".
*/

class stringAnagrams
{
    static vector<int> findStringAnagrams(const string& str, const string& pattern)
    {
        vector<int> resultIndices;
        if (str.length() < pattern.length()) return resultIndices;

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

            if (hash == 0) resultIndices.push_back(l);

            // remove str[l] from the hash
            ch = str[l];
            hash -= abs(patternCharCount[ch] - subStrCharCount[ch]);
            subStrCharCount[ch] -= 1;
            hash += abs(patternCharCount[ch] - subStrCharCount[ch]);
            l++;

            r++;
        }
        return resultIndices;
    }
};