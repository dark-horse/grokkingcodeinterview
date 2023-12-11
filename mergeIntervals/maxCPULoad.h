#pragma once

using namespace std;

#include<vector>
#include<queue>
#include<algorithm>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63936a049634a0fa11c91b2b */
/*
** We are given a list of Jobs. Each job has a Start time, an End time, and a CPU load when it is running. Our goal is to find the maximum CPU load at any time if all the jobs are running on the same machine.
** Example 1:
** Jobs: [[1,4,3], [2,5,4], [7,9,6]]
** Output: 7
** Explanation: Since [1,4,3] and [2,5,4] overlap, their maximum CPU load (3+4=7) will be when both the jobs are running at the same time i.e., during the time interval (2,4).
**
** Example 2:
** Jobs: [[6,7,10], [2,4,11], [8,12,15]]
** Output: 15
** Explanation: None of the jobs overlap, therefore we will take the maximum load of any job which is 15.
**
** Example 3:
** Jobs: [[1,4,2], [2,4,1], [3,6,5]]
** Output: 8
** Explanation: Maximum CPU load will be 8 as all jobs overlap during the time interval [3,4].
*/

class maxCPULoad
{
public:
    class Job {
    public:
        int start = 0;
        int end = 0;
        int cpuLoad = 0;

        Job(int start, int end, int cpuLoad) {
            this->start = start;
            this->end = end;
            this->cpuLoad = cpuLoad;
        }
    };

    struct endCompare {
        bool operator()(const Job& x, const Job& y) { return x.end > y.end; }
    };

    static int findMaxCPULoad(vector<Job>& jobs) {
        int maxCPULoad = 0;
        struct
        {
            bool operator() (Job a, Job b) { return a.start < b.start || (a.start == b.start && a.end < b.end); }
        }
        jobCompare;

        std::sort(jobs.begin(), jobs.end(), jobCompare);

        // the first int is the end time of the job,the second int is the cpuLoad of the job
        priority_queue<Job, vector<Job>, endCompare> minHeap = priority_queue<Job, vector<Job>, endCompare>();

        int priorityQueueCPULoad = 0;
        for (int i = 0; i < jobs.size(); i++)
        {
            Job currJob = jobs[i];
            while (!minHeap.empty() && minHeap.top().end <= currJob.start)
            {
                auto jobEnd = minHeap.top();
                if (jobEnd.end <= currJob.start)
                {
                    priorityQueueCPULoad -= jobEnd.cpuLoad;
                    minHeap.pop();
                }
            }
            minHeap.push(currJob);
            priorityQueueCPULoad += currJob.cpuLoad;
            maxCPULoad = max(maxCPULoad, priorityQueueCPULoad);
        }

        return maxCPULoad;
    }

};