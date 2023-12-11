#pragma once

using namespace std;

#include <vector>
#include <algorithm>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639245dffed07e597e96219f */


class insertInterval
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

    static vector<Interval> merge(const vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> mergedIntervals;
        vector<Interval> intervalsCopy = intervals;
        intervalsCopy.push_back(newInterval);

        struct
        {
            bool operator() (Interval a, Interval b) { return a.start < b.start || (a.start == b.start && a.end < b.end); }
        }
        intervalCompare;

        std::sort(intervalsCopy.begin(), intervalsCopy.end(), intervalCompare);

        int l = 0, r = 0, rBoundary = intervalsCopy[0].end;

        while (r < intervalsCopy.size())
        {
            while (r < intervalsCopy.size() && intervalsCopy[r].start <= rBoundary)
            {
                rBoundary = rBoundary > intervalsCopy[r].end ? rBoundary : intervalsCopy[r].end;
                r++;
            }

            Interval newInterval = Interval(intervalsCopy[l].start, rBoundary);
            mergedIntervals.push_back(newInterval);

            l = r;

            if (r < intervalsCopy.size()) rBoundary = intervalsCopy[r].end;
        }

        return mergedIntervals;
    }
};