#pragma once

using namespace std;

#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639249470cddc1617da1b889 */

/*
** Given two lists of intervals, find the intersection of these two lists. Each list consists of disjoint intervals sorted on their start time.
** Example 1:
** Input: arr1=[[1, 3], [5, 6], [7, 9]], arr2=[[2, 3], [5, 7]]
** Output: [2, 3], [5, 6], [7, 7]
** Explanation: The output list contains the common intervals between the two lists.
**
** Example 2:
** Input: arr1=[[1, 3], [5, 7], [9, 12]], arr2=[[5, 10]]
** Output: [5, 7], [9, 10]
** Explanation: The output list contains the common intervals between the two lists.
*/

class intervalsIntersection
{
public:
    class Interval
    {
    public:
        int start = 0;
        int end = 0;

        Interval(int start, int end) {
            this->start = start;
            this->end = end;
        }

        // the magic formula (magic function signature) to use for equality test when comparing vectors.
        bool operator==(const Interval& a) const { return this->start == a.start && this->end == a.end; }
    };

    static vector<Interval> merge(const vector<Interval>& arr1,
        const vector<Interval>& arr2) {
        vector<Interval> result;
        int curr1 = 0, curr2 = 0;
        while (curr1 < arr1.size() && curr2 < arr2.size())
        {
            Interval i1 = arr1[curr1], i2 = arr2[curr2];
            if (i1.start <= i2.end && i2.start <= i1.end)
            {
                int newStart = i1.start > i2.start ? i1.start : i2.start;
                int newEnd = i1.end > i2.end ? i2.end : i1.end;
                Interval newInterval = Interval(newStart, newEnd);
                result.push_back(newInterval);
            }

            if (i1.end > i2.end)
            {
                curr2++;
            }
            else if (i1.end < i2.end)
            {
                curr1++;
            }
            else
            {
                curr1++;
                curr2++;
            }
        }

        return result;
    }
};