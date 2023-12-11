#pragma once

using namespace std;

#include<vector>
#include<algorithm>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63936f6bb15a00b56fb3cf01 */
/*
** For ‘K’ employees, we are given a list of intervals representing each employee’s working hours.
** Our goal is to determine if there is a free interval which is common to all employees.
** You can assume that each list of employee working hours is sorted on the start time.
**
** Example 1:
** Input: Employee Working Hours=[[[1,3], [5,6]], [[2,3], [6,8]]]
** Output: [3,5]
** Explanation: All the employees are free between [3,5].
**
** Example 2:
** Input: Employee Working Hours=[[[1,3], [9,12]], [[2,4]], [[6,8]]]
** Output: [4,6], [8,9]
** Explanation: All employees are free between [4,6] and [8,9].
**
** Example 3:
** Input: Employee Working Hours=[[[1,3]], [[2,4]], [[3,5], [7,9]]]
** Output: [5,7]
** Explanation: All employees are free between [5,7].
*/

class employeeFreeTime
{
public:
    class Interval {
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
    struct startCompare {
        bool operator()(const pair<Interval, pair<int, int>>& x,
            const pair<Interval, pair<int, int>>& y) {
            return x.first.start > y.first.start;
        }
    };

    static vector<Interval> findEmployeeFreeTime(const vector<vector<Interval>>& schedule) {
        vector<Interval> result;
        if (schedule.size() == 0) return result;

        int workDayStart = INT32_MAX, workDayEnd = INT32_MIN;
        for (int i = 0; i < schedule.size(); i++)
        {
            for (int j = 0; j < schedule[i].size(); j++)
            {
                workDayStart = min(workDayStart, schedule[i][j].start);
                workDayEnd = max(workDayEnd, schedule[i][j].end);
            }
        }

        result = freeTime(schedule[0], workDayStart, workDayEnd);

        for (int i = 1; i < schedule.size(); i++)
        {
            vector<Interval> empFreeTime = freeTime(schedule[i], workDayStart, workDayEnd);
            result = intersectIntervals(result, empFreeTime);
        }

        return result;
    }

private:
    static vector<Interval> freeTime(vector<Interval> work, int workDayStart, int workDayEnd)
    {
        vector<Interval> res;

        // This problem has a weird rule about when the work day starts and ends.
        // In the real world people's work day starts when their first shift starts.
        // And it ends when the last shift ends.
        // (In particular this means people with one shift get no breaks).
        // in grokking the code interview world, work day starts when the earliest
        // worker's first shift ends; and it ends when the last worker's last shift ends.

        if (work[0].start > workDayStart) res.push_back(Interval(workDayStart, work[0].start));

        int start = work[0].end;
        for (int i = 1; i < work.size(); i++)
        {
            res.push_back(Interval(start, work[i].start));
            start = work[i].end;
        }

        if (work[work.size() - 1].end < workDayEnd) res.push_back(Interval(work[work.size()-1].end, workDayEnd));

        return res;
    }

    /// <summary>
    /// vectors a and b are sorted asscendingly by start / end time.
    /// the intervals in vectors a and b are disjoint.
    /// </summary>
    /// <param name="a"></param>
    /// <param name="b"></param>
    /// <returns></returns>
    static vector<Interval> intersectIntervals(vector<Interval> a, vector<Interval>b)
    {
        vector<Interval> res;
        if (a.size() == 0 || b.size() == 0) return res;
        int currA = 0, currB = 0;
        while (currA < a.size() && currB < b.size())
        {
            if (a[currA].start < b[currB].end && b[currB].start < a[currA].end)
            {
                // intersection...
                int start = max(a[currA].start, b[currB].start);
                int end = min(a[currA].end, b[currB].end);
                res.push_back(Interval(start, end));
            }

            if (a[currA].end > b[currB].end)
            {
                currB++;
            }
            else if (a[currA].end < b[currB].end)
            {
                currA++;
            }
            else
            {
                currA++;
                currB++;
            }
        }

        return res;
    }
};