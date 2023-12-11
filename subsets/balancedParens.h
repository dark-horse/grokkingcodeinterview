#pragma once

using namespace std;

#include<vector>
#include<string>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639cbb3b4374f9a7aada8ed0 */

/*
** For a given number ‘N’, write a function to generate all combination of ‘N’ pairs of balanced parentheses.
**
** Example 1:
** Input: N=2
** Output: (()), ()()
**
** Example 2:
** Input: N=3
** Output: ((())), (()()), (())(), ()(()), ()()()
*/

class balancedParens
{
public:
    static vector<string> generateValidParentheses(int num)
    {
        vector<string> result;
        if (num == 0) return vector<string>(1, "");
        if (num == 1) return vector<string>(1, "()");

        vector<vector<string>> cache;
        cache.push_back(vector<string>(1, "()"));
        vector<string> cache1 {"()()", "(())"};
        cache.push_back(cache1);

        validParensWithMnemonic(num-1, cache);

        for (auto s : cache[num - 1])
        {
            result.push_back(s);
        }

        // TODO: Write your code here
        return result;
    }

private:
    static void validParensWithMnemonic(int num, vector<vector<string>>& cache)
    {
        if (num < cache.size()) return;
        vector<string> add;
        // recursion step
        validParensWithMnemonic(num - 1, cache);
        // add the "() previous" and "( previous )"'"
        vector<string> previous = cache[cache.size() - 1];
        for (int i = 0; i < previous.size(); i++)
        {
            add.push_back("()" + previous[i]);
            add.push_back("(" + previous[i] + ")");
        }

        for (int i = 0; i < cache.size() - 1; i++)
        {
            int j = cache.size() - 2 - i;
            vector<string> iVector = cache[i];
            vector<string> jVector = cache[j];
            for (auto iStr : iVector)
            {
                for (auto jStr : jVector)
                {
                    add.push_back("(" + iStr + ")" + jStr);
                }
            }
        }

        cache.push_back(add);
    }
};