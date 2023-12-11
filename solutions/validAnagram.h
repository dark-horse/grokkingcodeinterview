#pragma once
#include <iostream>

using namespace std;


/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63d93a25970f20b6d90eef04 */
class validAnagram
{
private:
    void countLetters(string s, int* lowerCaseCount, int* upperCaseCount)
    {
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch >= 'a' && ch <= 'z') lowerCaseCount[(int)ch - 'a']++;
            if (ch >= 'A' && ch <= 'Z') upperCaseCount[(int)ch - 'a']++;
        }
    }

public:
    bool valid(string a, string b)
    {
#define alphaCount 24

        int lowerCaseLetterA[alphaCount] = {0};
        int upperCaseLetterA[alphaCount] = { 0 };
        int lowerCaseLetterB[alphaCount] = { 0 };
        int upperCaseLetterB[alphaCount] = { 0 };
        countLetters(a, lowerCaseLetterA, upperCaseLetterA);
        countLetters(b, lowerCaseLetterB, upperCaseLetterB);

        for (int i = 0; i < alphaCount; i++)
        {
            if (lowerCaseLetterA[i] != lowerCaseLetterB[i]) return false;
            if (upperCaseLetterA[i] != upperCaseLetterB[i]) return false;
        }

        return true;
    }
};
