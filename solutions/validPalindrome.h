#pragma once
#include <iostream>

using namespace std;

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63d92beaa4af7161a01dff44 */

class validPalindrome
{
private:
    bool isLetter(char ch)
    {
        return (ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A');
    }

    bool lowerCaseEqual(char a, char b)
    {
        a = (a >= 'A' && a <= 'Z') ? 'a' + (a - 'A') : a;
        b = (b >= 'A' && b <= 'Z') ? 'a' + (b - 'A') : b;
        return a == b;
    }

public:
    bool valid(string s)
    {
        if (s.length() <= 1) return true;

        for (size_t l = 0, r = s.length() - 1; l<r; l++, r--)
        {
            while (!isLetter(s[l]) && l < r) l++;
            while (!isLetter(s[r]) && l < r) r--;
            if (l >= r) break;
            if (!lowerCaseEqual(s[l], s[r])) return false;
        }

        return true;
    }
};
