#pragma once

#include <unordered_set>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63911273cf5aba4f2f70b5fe */

/*
** Any number will be called a happy number if, after repeatedly replacing it with a number equal to the sum of the square of all of its digits, leads us to the number 1. All other (not-happy) numbers will never reach 1. Instead, they will be stuck in a cycle of numbers that does not include 1.
** Given a positive number n, return true if it is a happy number otherwise return false.
** Example 1:
** Input: 23
** Output: true (23 is a happy number)
** Explanations: Here are the steps to find out that 23 is a happy number:

2^2 + 3^2 = 4 + 9 = 13
1^2 + 3^2 = 1 + 9 = 10
1^2 + 0^2 = 1 + 0 = 1
*/

class happyNumber
{
public:
    static bool find(int num) {
        auto hashMap = unordered_set<int>();

        hashMap.insert(num);
        while (num!=1)
        {
            num = calcSumDigitsSquare(num);
            if (num == 1) return true;
            if (hashMap.find(num) != hashMap.end()) return false;
            hashMap.insert(num);
        }

        return true;
    }

private:
    static int calcSumDigitsSquare(int num)
    {
        int res = 0;
        while (num != 0)
        {
            int remainder = num % 10;
            res += remainder * remainder;
            num = num / 10;
        }

        return res;
    }
};