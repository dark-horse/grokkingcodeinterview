#pragma once

using namespace std;

#include <vector>
#include <algorithm>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639363de4599b3e5714ab022 */
/*
** Given an array of intervals representing ‘N’ appointments, find out if a person can attend all the appointments.
**
** Example 1:
** Appointments: [[1,4], [2,5], [7,9]]
** Output: false
** Explanation: Since [1,4] and [2,5] overlap, a person cannot attend both of these appointments.
**
** Example 2:
** Appointments: [[6,7], [2,4], [8,12]]
** Output: true
** Explanation: None of the appointments overlap, therefore a person can attend all of them.
**
** Example 3:
** Appointments: [[4,5], [2,3], [3,6]]
** Output: false
** Explanation: Since [4,5] and [3,6] overlap, a person cannot attend both of these appointments.
*/

class conflictingAppointments
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

    static bool canAttendAllAppointments(vector<Interval>& intervals) {
        struct
        {
            bool operator() (Interval a, Interval b) { return a.start < b.start || (a.start == b.start && a.end < b.end); }
        }
        intervalCompare;

        std::sort(intervals.begin(), intervals.end(), intervalCompare);

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start < intervals[i - 1].end) return false;
        }

        return true;
    }
};