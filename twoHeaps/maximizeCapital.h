#pragma once

using namespace std;

#include<vector>
#include<queue>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639c960d0ce4573267ea5666 */

/*
** Given a set of investment projects with their respective profits, we need to find the most profitable projects.
** We are given an initial capital and are allowed to invest only in a fixed number of projects.
** Our goal is to choose projects that give us the maximum profit.
** Write a function that returns the maximum total capital after selecting the most profitable projects.
**
** We can start an investment project only when we have the required capital. After selecting a project, we can assume that its profit has become our capital, and that we have also received our capital back.
**
** Example 1:
** Input: Project Capitals=[0,1,2], Project Profits=[1,2,3], Initial Capital=1, Number of Projects=2
** Output: 6
** Explanation:
** 1. With initial capital of ‘1’, we will start the second project which will give us profit of ‘2’. Once we selected our first project, our total capital will become 3 (profit + initial capital).
** 2. With ‘3’ capital, we will select the third project, which will give us ‘3’ profit.
**
** After the completion of the two projects, our total capital will be 6 (1+2+3).
**
** Example 2:
** Input: Project Capitals=[0,1,2,3], Project Profits=[1,2,3,5], Initial Capital=0, Number of Projects=3
** Output: 8
** Explanation:
** 1. With ‘0’ capital, we can only select the first project, bringing out capital to 1.
** 2. Next, we will select the second project, which will bring our capital to 3.
** 3. Next, we will select the fourth project, giving us a profit of 5.
**
After selecting the three projects, our total capital will be 8 (1+2+5).
**
**
** Unspecified situation: you can go back to a project at the beginning of the array if is advangateous
** Example 3:
** Input: Project Capitals=[2,2,1], Project Profits=[100,2,30], Initial Capital=1, Number of Projects=2
** Output: 131
** Explanation:
** 1. With ‘1’ capital, we take the past project - which will bring capital to 31.
** 2. Next, we will select the first project, which will bring our capital to 31 + 100 = 131.
*/

class maximizeCapital
{
public:
    static int findMaximumCapital(const vector<int>& capital, const vector<int>& profits,
        int numberOfProjects, int initialCapital)
    {
        priority_queue<project, vector<project>, project::GreaterThanByProfit> lowCostQueue;
        priority_queue<project, vector<project>, project::GreaterThanByCost> higherCostQueue;
        for (int i = 0; i < capital.size(); i++)
        {
            project prj(capital[i], profits[i]);
            if (prj.cost <= initialCapital) lowCostQueue.push(prj);
            else higherCostQueue.push(prj);

        }

        while (numberOfProjects > 0)
        {
            // loop invariant: initialCapital < higherCostQueue.top().cost or higherCostQueue is empty.
            // loop invariant: initialCapital > lowCostQueue.top().cost
            if (lowCostQueue.empty()) break;
            initialCapital += lowCostQueue.top().profit;
            lowCostQueue.pop();
            numberOfProjects--;

            while (!higherCostQueue.empty() && higherCostQueue.top().cost <= initialCapital)
            {
                lowCostQueue.push(higherCostQueue.top());
                higherCostQueue.pop();
            }
        }

        return initialCapital;
    }
private:
    class project
    {
    public:
        int cost;
        int profit;
        project(int cost, int profit) : cost(cost), profit(profit) {}

        struct GreaterThanByProfit
        {
            bool operator()(const project& lhs, const project& rhs) const
            {
                return lhs.profit < rhs.profit;
            }
        };

        struct GreaterThanByCost
        {
            bool operator()(const project& lhs, const project& rhs) const
            {
                return lhs.cost > rhs.cost;
            }
        };
    };
};