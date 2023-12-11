#pragma once

using namespace std;

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639366c54599b3e5714ab178 */

/*
** Given a list of intervals representing the start and end time of ‘N’ meetings, find the minimum number of rooms required to hold all the meetings.
**
** Example 1:
** Meetings: [[1,4], [2,5], [7,9]]
** Output: 2
** Explanation: Since [1,4] and [2,5] overlap, we need two rooms to hold these two meetings. [7,9] can occur in any of the two rooms later.
**
** Example 2:
** Meetings: [[6,7], [2,4], [8,12]]
** Output: 1
** Explanation: None of the meetings overlap, therefore we only need one room to hold all meetings.
**
** Example 3:
** Meetings: [[1,4], [2,3], [3,6]]
** Output:2
** Explanation: Since [1,4] overlaps with the other two meetings [2,3] and [3,6], we need two rooms to hold all the meetings.
**
** Example 4:
** Meetings: [[4,5], [2,3], [2,4], [3,5]]
** Output: 2
** Explanation: We will need one room for [2,3] and [3,5], and another room for [2,4] and [4,5].
*/

class minimumMeetingRooms
{
public:
    class Meeting
    {
    public:
        int start = 0;
        int end = 0;

        Meeting(int start, int end) {
            this->start = start;
            this->end = end;
        }

        // the magic formula (magic function signature) to use for equality test when comparing vectors.
        bool operator==(const Meeting& a) const { return this->start == a.start && this->end == a.end; }
    };

    static int findMinimumMeetingRooms(vector<Meeting>& meetings) {
        int minRooms = 0;
        unordered_map<unsigned int, int> interviewEnds = unordered_map<unsigned int, int>();
        unordered_set<unsigned long long int> rowInterviewEndUsed = unordered_set<unsigned long long int>();
        // we need to store both the endpoint and whether or not is a start/endpoint.
        // we will rely on the fact that the interview start/end are positive integers.
        // And store the stard/end state in the significant most bit (the sign bit)
        // 1 is for start, 0 is for end.
        unsigned int intMask = 0x80000000;
        for (int i = 0; i < meetings.size(); i++)
        {
            int startI = meetings[i].start, endI = meetings[i].end;
            for (int j = 0; j < meetings.size(); j++)
            {
                // oops, rules changed again for 0-length meetings..... (meeting [2,2] or [3,3] for example)
                // 1. if the 0-length meeting is contained within the interval it counts once (so multiple instances of the same [2,2] meeting are counted only once)
                //          (multiple instances of non-emtpy meetings are counted once for every instance)
                //          so [2,2] and [2,2] and [2,2] are counted exactly once in [1,3] and [1,5] and [1,10] etc....
                // 2. if any other non-empty meeting has the same endpoint (start / end) as endpoints of 0-length meeting then the 0-length meeting does not count at all.
                //      In particular, this overrides item 1. above.
                if (startI == endI)
                {
                    continue;
                }
                else
                {
                    // regular case - not a 0-length meeting.
                    if (startI < meetings[j].end && startI >= meetings[j].start)
                    {
                        unsigned int hash = intMask | ((unsigned int)startI);
                        unsigned long long int rowInterviewEndUsedHash = (unsigned long long int) hash;
                        rowInterviewEndUsedHash = rowInterviewEndUsedHash << 32;
                        rowInterviewEndUsedHash |= (unsigned long long int) j;
                        if (rowInterviewEndUsed.find(rowInterviewEndUsedHash) == rowInterviewEndUsed.end())
                        {
                            interviewEnds[hash]++;
                            rowInterviewEndUsed.insert(rowInterviewEndUsedHash);
                            minRooms = minRooms < interviewEnds[hash] ? interviewEnds[hash] : minRooms;
                        }
                    }

                    if (endI <= meetings[j].end && endI > meetings[j].start)
                    {
                        unsigned int hash = (unsigned int)endI;
                        unsigned long long int rowInterviewEndUsedHash = (unsigned long long int) hash;
                        rowInterviewEndUsedHash = rowInterviewEndUsedHash << 32;
                        rowInterviewEndUsedHash |= (unsigned long long int) j;
                        if (rowInterviewEndUsed.find(rowInterviewEndUsedHash) == rowInterviewEndUsed.end())
                        {
                            interviewEnds[hash]++;
                            rowInterviewEndUsed.insert(rowInterviewEndUsedHash);
                            minRooms = minRooms < interviewEnds[hash] ? interviewEnds[hash] : minRooms;
                        }
                    }
                }
            }
        }

        return minRooms;
    }
};