#pragma once

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6385dac84a29c96532f7c6b7 */

/*
** Given a string and a list of words, find all the starting indices of substrings in the given string
** that are a concatenation of all the given words exactly once without any overlapping of words.
** It is given that all words are of the same length.
**
** Example 1:
** Input: String="catfoxcat", Words=["cat", "fox"]
** Output: [0, 3]
** Explanation: The two substring containing both the words are "catfox" & "foxcat".
**
** Example 2:
** Input: String="catcatfoxfox", Words=["cat", "fox"]
** Output: [3]
** Explanation: The only substring containing both the words is "catfox".
*/

class wordsConcatenation
{
public:
    static vector<int> findWordConcatenationSlowPoke(const string& str, const vector<string>& words)
    {
        vector<int> resultIndices;
        if (words.size() == 0) return resultIndices;
        if (str.length() < words.size() * words[0].length()) return resultIndices;  // all the words have the same length.

        // use it for a fast heuristic as to whether or not [l..r] contains all the letters in words...
        unordered_map<char, int> freqsAllChars = unordered_map<char, int>();
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            for (int j = 0; j < word.length(); j++) freqsAllChars[word[j]]++;
        }

        unordered_map<string, int> freqsAllWords = unordered_map<string, int>();
        for (int i = 0; i < words.size(); i++) freqsAllWords[words[i]]++;

        int wordLen = words[0].length(), concatLen = words.size() * wordLen;    // all words have the same length
        int charsMatched = concatLen;

        int l = 0, r = concatLen - 1;

        for (int i = 0; i < concatLen - 1; i++)
        {
            if (freqsAllChars.find(str[i]) != freqsAllChars.end())
            {
                freqsAllChars[str[i]]--;
                if (freqsAllChars[str[i]] >= 0) charsMatched--;
            }
        }

        while (r < str.length())
        {
            if (freqsAllChars.find(str[r]) != freqsAllChars.end())
            {
                freqsAllChars[str[r]]--;
                if (freqsAllChars[str[r]] >= 0) charsMatched--;
            }

            if (charsMatched == 0)
            {
                // [l..r] contains all the characters in words.
                int wordsMatched = words.size();
                int wordsChecked = 0;
                for (int i = 0; i < words.size(); i++)
                {
                    string subStr = str.substr(l + i * wordLen, wordLen);
                    if (freqsAllWords.find(subStr) != freqsAllWords.end())
                    {
                        freqsAllWords[subStr]--;
                        if (freqsAllWords[subStr] >= 0) wordsMatched--;
                        wordsChecked++;
                    }
                    else
                    {
                        break;
                    }
                }

                if (wordsMatched == 0) resultIndices.push_back(l);

                // reconstruct the freqsAllWords back....
                for (int i = 0; i < wordsChecked; i++)
                {
                    string subStr = str.substr(l + i * wordLen, wordLen);
                    if (freqsAllWords.find(subStr) != freqsAllWords.end())
                    {
                        if (freqsAllWords[subStr] >= 0) wordsMatched++;
                        freqsAllWords[subStr]++;
                    }
                }

                if (wordsMatched != words.size())
                {
                    // should assert that wordMatched == words.Size();
                    cout << "error: wordsMatched is " << wordsMatched << " and it should be " << words.size() << "\n";
                }
            }

            // move l forward
            if (freqsAllChars.find(str[l]) != freqsAllChars.end())
            {
                if (freqsAllChars[str[l]] >= 0) charsMatched++;
                freqsAllChars[str[l]]++;
            }

            l++;
            r++;
        }

        return resultIndices;
    }

    static vector<int> findWordConcatenation(const string& str,
        const vector<string>& words)
    {
        vector<int> resultIndices;
        if (words.size() == 0) return resultIndices;
        if (str.length() < words.size() * words[0].length()) return resultIndices;  // all the words have the same length.

        unordered_map<char, int> freqsAllChars = unordered_map<char, int>();
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            for (int j = 0; j < word.length(); j++) freqsAllChars[word[j]]++;
        }

        vector<wordChunk> wordChunks = vector<wordChunk>(words.size());
        unordered_map<wordChunk, int, wordChunk> freqsWords = unordered_map<wordChunk, int, wordChunk>();
        for (int i = 0; i < words.size(); i++)
        {
            wordChunks[i] = wordChunk(words[i], 0, words[i].length());
            freqsWords[wordChunks[i]]++;
        }

        int resLen = words.size() * words[0].length();
        int l = 0, r = resLen - 1;
        wordChunk resWordChunk = wordChunk(str, 0, resLen);

        return resultIndices;
    }

public: 
    class wordChunk
    {
    private:
        const char * str = nullptr;
        int start = 0, length = 0;
    public:
        wordChunk() noexcept {}


        wordChunk(const string& input, int start, int length): start(start), length(length)
        {
            str = input.c_str();
        }

        void shiftLeft()
        {
            start++;
        }

        bool operator==(const wordChunk& a) const noexcept
        {
            return this->length == a.length && memcmp(this->str + start, a.str + a.start, this->length) == 0;
        }

        std::size_t operator() (const wordChunk& w) const noexcept
        {
            size_t result = 0;
            const size_t prime = 31;
            for (size_t i = start; i < length; ++i) {
                result = str[i] + (result * prime);
            }
            return result;
        }

        ~wordChunk() noexcept
        {
        }
    };
};