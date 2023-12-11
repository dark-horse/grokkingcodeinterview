#pragma once

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_set>


/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6392394ee4cb724ea7189954 */

/*
** We are given an array containing positive and negative numbers.
** Suppose the array contains a number ‘M’ at a particular index.
** Now, if ‘M’ is positive we will move forward ‘M’ indices and if ‘M’ is negative move backwards ‘M’ indices.
** You should assume that the array is circular which means two things:

** If, while moving forward, we reach the end of the array, we will jump to the first element to continue the movement.
** If, while moving backward, we reach the beginning of the array, we will jump to the last element to continue the movement.
** Write a method to determine if the array has a cycle.
** The cycle should have more than one element and should follow one direction which means the cycle should not contain both forward and backward movements.
*/

class cycleCircularArray
{
public:
    static bool loopExists(const vector<int>& arr) {
        if (arr.size() == 0 || arr.size() == 1) return false;
        auto visited = unordered_set<int>();
        int arrSz = arr.size();
        for (int i = 0; i < arrSz; i++)
        {
            if (arr[i] == 0) continue;  // apparently 0 is not part of the input, but who knows....

            if (visited.find(i) != visited.end()) continue; // already visited this node and it is not part of a a cycle.

            auto localLoop = unordered_set<int>();
            int next = i;
            localLoop.insert(next);
            visited.insert(next);

            while (true)
            {
                int nextCandidate = (next + arr[next]) % arrSz;
                // c++ cannot do modulo arithmetic correctly.....
                // if (next + arr[next]) is negative, then the remainder will be negative too...
                // What a joke!!!
                nextCandidate = (nextCandidate + arrSz) % arrSz;
                if (nextCandidate == next) break;  // cycle must have more than 1 element

                next = nextCandidate;

                if (arr[next] == 0) break;  // apparently 0 is not part of the input, but who knows...

                // continue only if arr[next] and arr[i] have the same sign.
                if ((arr[next] < 0 && arr[i] > 0) || (arr[next] > 0 && arr[i] < 0)) break;

                if (localLoop.find(next) != localLoop.end()) return true;   // found a loop
                if (visited.find(next) != visited.end()) break; // already visited this node and is not part of a cycle.

                localLoop.insert(next);
                visited.insert(next);
            }
        }

        return false;
    }
};