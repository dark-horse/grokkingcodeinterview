#pragma once
#include<iostream>
using namespace std;

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63d9b8744bb2155485a195e9 */

class reverseVowels
{
private:
    bool IsVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

public:
    void reverse(string & s)
    {
        if (s.length() <= 1) return;
        size_t l = 0, r = s.length() - 1;
        while (l < r)
        {
            while (!IsVowel(s[l]) && l < r) l++;
            while (!IsVowel(s[r]) && l < r) r--;
            if (l >= r) break;
            std::swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};