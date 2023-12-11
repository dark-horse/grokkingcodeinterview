#pragma once

using namespace std;

#include<vector>
#include<string>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639cb0c8f9c10047d0529044 */
/*
** Given a string, find all of its permutations preserving the character sequence but changing case.
**
** Example 1:
** Input: "ad52"
** Output: "ad52", "Ad52", "aD52", "AD52"
**
** Example 2:
** Input: "ab7c"
** Output: "ab7c", "Ab7c", "aB7c", "AB7c", "ab7C", "Ab7C", "aB7C", "AB7C"
** 
** (Wrong use of word permutation, by the way...)
** 
*/

class stringPermutationsChangeCase
{
public:
    static vector<string> findLetterCaseStringPermutations(const string& str)
    {
        vector<string> permutations;
        permutations.push_back(str);
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (ch <= 'z' && ch >= 'a')
            {
                int sz = permutations.size();
                for (int j = 0; j < sz; j++)
                {
                    string change = permutations[j];
                    change[i] = ch - 'a' + 'A';
                    permutations.push_back(change);
                }
            }
            else if (ch <= 'Z' && ch >= 'A')
            {
                int sz = permutations.size();
                for (int j = 0; j < sz; j++)
                {
                    string change = permutations[j];
                    change[i] = ch - 'A' + 'a';
                    permutations.push_back(change);
                }
            }
        }
        return permutations;
    }
};