#pragma once

using namespace std;

#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6385d2dae25dea6343fd8b19 */
/*
** You are visiting a farm to collect fruits. The farm has a single row of fruit trees.
** You will be given two baskets, and your goal is to pick as many fruits as possible to be placed in the given baskets.
**
** You will be given an array of characters where each character represents a fruit tree. The farm has following restrictions:
** Each basket can have only one type of fruit. There is no limit to how many fruit a basket can hold.
** You can start with any tree, but you can’t skip a tree once you have started.
** You will pick exactly one fruit from every tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.
** Write a function to return the maximum number of fruits in both baskets.
**
** Example 1:
** Input: Fruit=['A', 'B', 'C', 'A', 'C']
** Output: 3
** Explanation: We can put 2 'C' in one basket and one 'A' in the other from the subarray ['C', 'A', 'C']
**
** Example 2:
** Input: Fruit = ['A', 'B', 'C', 'B', 'B', 'C']  
** Output: 5
** Explanation: We can put 3 'B' in one basket and two 'C' in the other basket. This can be done if we start with the second letter: ['B', 'C', 'B', 'B', 'C']
**
*/


/* looks a lot like the longestSubstring with 2 characters....*/
class fruitsIntoBaskets
{
    static int findLength(const vector<char>& arr)
    {
        if (arr.size() <= 1) return arr.size();

        int wndChars[CHAR_MAX - CHAR_MIN + 1]{ 0 };

        int l = 0, r = 0, len = 0, distinctCharsCount = 0;

        while (r < arr.size())
        {
            distinctCharsCount += updateWndChars(wndChars, arr[r], true);

            while (r < arr.size() - 1 && distinctCharsCount <= 2)
            {
                int newLen = r - l + 1;
                len = newLen > len ? newLen : len;
                r++;
                distinctCharsCount += updateWndChars(wndChars, arr[r], true);
            }

            if (distinctCharsCount <= 2)
            {
                int newLen = r - l + 1;
                len = newLen > len ? newLen : len;
            }

            while (l <= r && distinctCharsCount > 2)
            {
                distinctCharsCount += updateWndChars(wndChars, arr[l], false);
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