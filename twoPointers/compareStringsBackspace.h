using namespace std;

#include <iostream>
#include <string>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/638fa28f5844e928cbefff88 */
/*
** Given two strings containing backspaces (identified by the character ‘#’), check if the two strings are equal.
** Example 1:
** Input: str1="xy#z", str2="xzz#"
** Output: true
** Explanation: After applying backspaces the strings become "xz" and "xz" respectively.
*/

class compareStringsBackspace
{
public:
    static bool compare(const string& str1, const string& str2) {
        int str1Index = skipBackspaces(str1, str1.length()-1);
        int str2Index = skipBackspaces(str2, str2.length()-1);
        while (str1Index >= 0 && str2Index >= 0)
        {
            str1Index = skipBackspaces(str1, str1Index);
            str2Index = skipBackspaces(str2, str2Index);

            if (str2Index < 0 || str1Index < 0) break;

            if (str1[str1Index] != str2[str2Index]) return false;

            str1Index--;
            str2Index--;
        }

        return str1Index == -1 && str2Index == -1;
    }

private:
    static int skipBackspaces(const string& str, int startIndex)
    {
        int skip = 0;
        while (startIndex >= 0 && (str[startIndex] == '#' || skip > 0))
        {
            skip += str[startIndex] == '#' ? +1 : -1;
            startIndex--;
        }

        return startIndex;
    }
};