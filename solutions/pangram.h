#include<iostream>
using namespace std;

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63d923d6647c5c53032694bc */
class pangram
{
public:
    bool checkIfPangram(string sentence)
    {
        bool chars[26] = { false };
        int charsPresent = 0;

        for (int i = 0; i < sentence.length(); i++)
        {
            char ch = sentence[i];
            if (ch >= 'a' && ch <= 'z')
            {
                int index = (int)ch - 'a';
                if (!chars[index])
                {
                    charsPresent++;
                }
                chars[index] = true;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                int index = (int)ch - 'A';
                if (!chars[index])
                {
                    charsPresent++;
                }
                chars[index] = true;
            }

            //bail out early
            if (charsPresent == 26) return true;
        }

        return charsPresent == 26;
    }
};
